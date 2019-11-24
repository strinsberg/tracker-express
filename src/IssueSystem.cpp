#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include "Comment.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <nlohmann/json.hpp>

IssueSystem::IssueSystem() : issueCount(1), userCount(1),
commentCount(1) {}

IssueSystem::~IssueSystem() {}


// Object creation ///////////////////////////////////////////////////////

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
 
Issue& IssueSystem::createIssue(const std::string& json) {
    auto data = nlohmann::json::parse(clean(json));

    // For loading state set a different newId
    int newId = issueCount;
    if (data.find("id") != data.end()) {
        newId = data["id"];
        if (issueCount <= newId)
            issueCount = newId + 1;
    } else {
        issueCount++;
    }

    // create the issue and set all its fields with update
    issues.push_back(Issue(newId));
    Issue& iss = issues.back();
    iss.update(data);

    return iss;
}

User& IssueSystem::createUser(const std::string& json) {
    auto data = nlohmann::json::parse(clean(json));

    // If loading a user set the newId accordingly
    int newId = userCount;
    if (data.find("id") != data.end()) {
        newId = data["id"];
        if (userCount <= newId)
            userCount = newId + 1;
    } else {
        userCount++;
    }

    // Create user and set it up
    users.push_back(User(newId));
    User& user = users.back();
    user.update(data);

    return user;
}

Comment& IssueSystem::createComment(const std::string& json) {
    auto data = nlohmann::json::parse(clean(json));

    // If loading a comment set the newId properly
    int newId = commentCount;
    if (data.find("id") != data.end()) {
        newId = data["id"];
        if (commentCount <= newId)
            commentCount = newId + 1;
    } else {
        commentCount++;
    }

    // Create and setup comment
    comments.push_back(Comment(newId));
    Comment& com = comments.back();
    com.update(data);

    return com;
}


// Getters ///////////////////////////////////////////////////////////////

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


// Object Removal ////////////////////////////////////////////////////////

void IssueSystem::removeIssue(int id) {
    for (size_t i = 0; i < issues.size(); i++) {
        if (id == issues.at(i).getId()) {
            issues.erase(issues.begin() + i);
            issueCount--;
            return;
        }
    }
    throw std::invalid_argument("Error: Not a valid ID");
}

void IssueSystem::removeUser(int id) {
    for (size_t i = 0; i < users.size(); i++) {
        if (id == users.at(i).getId()) {
            users.erase(users.begin() + i);
            userCount--;
            return;
        }
    }
    throw std::invalid_argument("Error: Not a valid ID");
}

void IssueSystem::removeComment(int id) {
    for (size_t i = 0; i < comments.size(); i++) {
        if (id == comments.at(i).getId()) {
            comments.erase(comments.begin() + i);
            commentCount--;
            return;
        }
    }
    throw std::invalid_argument("Error: Not a valid ID");
}


// Object list filters ///////////////////////////////////////////////////
#include <iostream>
std::vector<Comment> IssueSystem::filterComments(int id) {
    std::vector<Comment> coms;

    for (auto com : comments) {
        if (com.getIssueId() == id)
            coms.push_back(com);
    }
    return coms;
}

std::vector<Issue> IssueSystem::filterIssues(int priority, std::string tag,
        int status) {
    std::vector<Issue> filtered(issues);
    auto begin = filtered.begin();
    auto end = filtered.end();

    if (priority != -1) {
        end = std::remove_if(begin, end, [priority](Issue& iss) {
            return iss.getPriority() != priority;
        });
    }

    if (status != -1) {
        end = std::remove_if(begin, end, [status](Issue& iss) {
            return iss.getStatus() != static_cast<Status>(status);
        });
    }

    if (tag != "") {
        end = std::remove_if(begin, end, [tag](Issue& iss) {
            std::vector<std::string> tags = iss.getTags();
            return std::find(tags.begin(), tags.end(), tag) != tags.end();
        });
    }

    filtered.erase(end + 1, issues.end());
    return filtered;
}


// Serialization /////////////////////////////////////////////////////////

std::string IssueSystem::serialize() {
    nlohmann::json data = {
        {"issues", {}},
        {"users", {}},
        {"comments", {}},
        {"issue_count", issueCount},
        {"user_count", userCount},
        {"comment_count", commentCount}
    };
    
    for (auto& iss : issues)
        data["issues"].push_back(iss.toJson().dump());

    for (auto& user : users)
        data["users"].push_back(user.toJson().dump());

    for (auto& com : comments)
        data["comments"].push_back(com.toJson().dump());

    return data.dump(4);
}

void IssueSystem::deserialize(const std::string& json) {
    auto system = nlohmann::json::parse(json);

    for (auto& iss : system["issues"])
        createIssue(iss.dump());

    for (auto& user : system["users"])
        createUser(user.dump());

    for (auto& com : system["comments"])
        createComment(com.dump());

    issueCount = system["issue_count"];
    userCount = system["user_count"];
    commentCount = system["comment_count"];
}

// private ///////////////////////////////////////////////////////////////

std::string IssueSystem::clean(std::string str) {
    size_t pos = str.rfind('}'); 
    if (pos != std::string::npos)
        return str.substr(0, pos+1);

    return str;
}
