#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include "Comment.h"
#include <vector>

IssueSystem::IssueSystem() : issueCount(1), userCount(1),
commentCount(1) {}

IssueSystem::~IssueSystem() {
    //dtor
}

int IssueSystem::createIssue() {
    //use issueCount in Issue CONSTR. - n/a yet
    issues.push_back(Issue()); //will be issueID = 1 to start
    //increment the issueCount for other issues created
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
    //no issueID implemented yet
}

User& IssueSystem::getUser(int id) {
    for (unsigned int i=0; i < users.size(); i++) {
        if (i == id-1)
            return users[i];
    }
    //shouldn't get here
    //return User();
}

Comment& IssueSystem::getComment(int id) {
    for (unsigned int i=0; i < comments.size(); i++) {
        if (i == id-1)
            return comments[i];
    }
    //shouldn't get here
    //return Comment();
}
