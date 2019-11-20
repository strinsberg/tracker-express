#include <iostream>
#include <string>
#include <vector>
#include "Issue.h"
#include "Status.h"
#include <nlohmann/json.hpp>

Issue::Issue(int newIssue) : priority(-1), assignee(-1), issueId(newIssue),
    creator(-1), status(Status::NEW), title("empty"), description("empty") {}

string Issue::getTitle() {
    return title;
}

int Issue::getId() {
   return issueId;
}

string Issue::getDescription() {
    return description;
}

int Issue::getPriority() {
    return priority;
}

int Issue::getAssignee() {
    return assignee;
}

int Issue::getCreator() {
    return creator;
}

vector<string> Issue::getTags() {
    return tags;
}

string Issue::getTagAtPos(int i) {
    return tags.at(i);
}

Status Issue::getStatus() {
    return Issue::status;
}

void Issue::setTitle(string newTitle) {
    title = newTitle;
}

void Issue::setDescription(string newDescription) {
    description = newDescription;
}

void Issue::setPriority(int newPriority) {
    priority = newPriority;
}

void Issue::setAssignee(int newAssignee) {
    assignee = newAssignee;
}

void Issue::setCreator(int id) {
    creator = id;
}

void Issue::addTag(string newTag) {
    tags.push_back(newTag);
}

void Issue::setStatus(Status s) {
    status = s;
}

void Issue::update(std::string json) {
    auto data = nlohmann::json::parse(json);

    if (data.find("title") != data.end())
        title = data["title"];
    if (data.find("description") != data.end())
        description = data["description"];
    if (data.find("priority") != data.end())
        priority = data["priority"];
    if (data.find("assignee") != data.end())
        assignee = data["assignee"];
    if (data.find("creator") != data.end())
        creator = data["creator"];
    if (data.find("status") != data.end())
        status = static_cast<Status>(data["status"]);
}

nlohmann::json Issue::toJson() {
    nlohmann::json data;

    data["id"] = issueId;
    data["title"] = title;
    data["description"] = description;
    data["priority"] = priority;
    data["assignee"] = assignee;
    data["creator"] = creator;
    data["status"] = status;
    nlohmann::json j_vec(tags);
    data["tags"] = j_vec.dump();

    return data;
}
