#include <nlohmann/json.hpp>
#include <string>
#include "Comment.h"

Comment::Comment(int comment_id) : commentId(comment_id), issueId(-1),
        userId(-1), text("empty text") {}

void Comment::setIssueId(int issue_id) {
    issueId = issue_id;
}

void Comment::setUserId(int user_id) {
    userId = user_id;
}

void Comment::setCommentText(string comment) {
    text = comment;
}

int Comment::getId() {
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

nlohmann::json Comment::toJson() {
    nlohmann::json data;
    return data;
}
