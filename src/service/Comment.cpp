#include<string>
#include "Comment.h"

Comment::Comment(int comment_id) {
    //ctor
    commentId = comment_id;
}

void Comment::setIssueId(int issue_id) {
    issueId = issue_id;
}

void Comment::setUserId(int user_id) {
    userId = user_id;
}

void Comment::setCommentText(string comment) {
    text = comment;
}

int Comment::getCommentId() {
    return commentId;
}

int Comment::getIssueId() {
    return issueId;
}

int Comment::getUserId() {
    return userId;
}

string Comment::getCommentText() {
    return text;
}

Comment::~Comment() {
    //dtor
}
