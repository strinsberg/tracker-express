#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include "Comment.h"
#include <vector>
#include <stdexcept>
#include <nlohmann/json.hpp>

IssueSystem::IssueSystem() : issueCount(1), userCount(1),
commentCount(1) {}

IssueSystem::~IssueSystem() {}

int IssueSystem::createIssue() {
    issues.push_back(Issue(issueCount));
    return issueCount++;
}

int IssueSystem::createUser() {
    users.push_back(User(userCount));
    return userCount++;
}

int IssueSystem::createComment() {
    comments.push_back(Comment(commentCount));
    return commentCount++;
}
 
Issue& IssueSystem::createIssue(const char* json) {
    issues.push_back(Issue(issueCount));
    issueCount++;

    Issue& iss = issues.back();

    auto data = nlohmann::json::parse(clean(std::string(json)));

    iss.setTitle(data["title"]);
    iss.setDescription(data["description"]);
    iss.setAssignee(data["assignee"]);
    iss.setCreator(data["creator"]);
    iss.setPriority(data["priority"]);

    if (iss.getAssignee() == -1)
        iss.setStatus(Status::NEW);
    else
        iss.setStatus(Status::ASSIGNED);

    return iss;
}

User& IssueSystem::createUser(const char* json) {
    users.push_back(User(userCount));
    userCount++;

    auto data = nlohmann::json::parse(clean(std::string(json)));

    User& user = users.back();

    user.setName(data["name"]);
    user.setBlurb(data["blurb"]);
    user.setPictureNum(data["pic"]);
    
    return user;
}

Comment& IssueSystem::createComment(const char* json) {
    comments.push_back(Comment(commentCount));
    commentCount++;
    
    Comment& com = comments.back();
    return com;
}

std::vector<Issue>& IssueSystem::getIssues() {
    return issues;
}

std::vector<User>& IssueSystem::getUsers() {
    return users;
}

std::vector<Comment>& IssueSystem::getComments() {
    return comments;
}

Issue& IssueSystem::getIssue(int id) {
    for (size_t i = 0; i < issues.size(); i++) {
        if (id == issues.at(i).getId())
            return issues.at(i);
    }
    throw std::invalid_argument("Error: Not a valid ID");
}

User& IssueSystem::getUser(int id) {
    for (size_t i = 0; i < users.size(); i++) {
        if (id == users.at(i).getId())
            return users.at(i);
    }
    throw std::invalid_argument("Error: Not a valid ID");
}

Comment& IssueSystem::getComment(int id) {
    for (size_t i = 0; i < comments.size(); i++) {
        if (id == comments.at(i).getId())
            return comments[i];
    }
    throw std::invalid_argument("Error: Not a valid ID");
}

std::string IssueSystem::clean(std::string str) {
    return str;
}
