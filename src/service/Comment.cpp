#include<string>
#include "Comment.h"

Comment::Comment(int comment_id) {
    //ctor
    commentID = comment_id;
}

void Comment::setIssueID(int issue_id) {
    issueID = issue_id;
}

void Comment::setUserID(int user_id) {
    userID = user_id;
}

void Comment::setCommentText(string comment) {
    text = comment;
}

int Comment::getCommentID() {
    return commentID;
}

int Comment::getIssueID() {
    return issueID;
}

int Comment::getUserID() {
    return userID;
}

string Comment::getCommentText() {
    return text;
}

Comment::~Comment() {
    //dtor
}
