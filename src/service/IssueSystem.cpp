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
    issueCount++;
    //return the id of the issue just created
    return issueCount - 1;
}

int IssueSystem::createUser() {
    bool valid = false;
    //condition to set input to true??
    if (valid) {
        //create a user with the id of the current userCount
        users.push_back(User(userCount));
        //increment the userCount for further user creation
        userCount++;
        //return the count of the user just created
        return userCount - 1;
    } else {
        return -1;
    }
}

int IssueSystem::createComment() {
    bool valid = false;
    //condition to set input to true??
    if (valid) {
        //create a comment with the id of the current commentCount
        comments.push_back(Comment(commentCount));
        //increment the commentCount for further comment creation
        commentCount++;
        //return the count of the comment just created
        return commentCount - 1;
    } else {
        return -1;
    }
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
    //CHECKPOINT
    //WHAT TO DO WITH ISSUE&??!?!?!?!
}

User& IssueSystem::getUser(int id) {

}

Comment& IssueSystem::getComment() {

}
