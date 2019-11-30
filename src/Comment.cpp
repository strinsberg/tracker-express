#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include "Comment.h"

using std::string;

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

void Comment::update(nlohmann::json data) {
    if (data.find("issue_id") != data.end())
        issueId = data["issue_id"];
    if (data.find("user_id") != data.end())
        userId = data["user_id"];
    if (data.find("text") != data.end())
        text = data["text"];
}

void Comment::update(std::string json) {
    auto data = nlohmann::json::parse(json);
    update(data);
}

nlohmann::json Comment::toJson() {
    nlohmann::json data;

    data["id"] = commentId;
    data["issue_id"] = issueId;
    data["user_id"] = userId;
    data["text"] = text;

    return data;
}
