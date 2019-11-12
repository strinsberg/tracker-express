#include <iostream>
#include <string>
#include <vector>
#include "Issue.h"
#include "Status.h"

Issue::Issue(int newIssue) : priority(-1), assignee(-1), issueId(newIssue),
    creator(-1), status(Status::NEW) {}

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
