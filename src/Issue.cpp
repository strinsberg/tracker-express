#include <iostream>
#include <string>
#include <vector>
#include "include/Issue.h"

string Issue::getTitle() {
    return title;
}

string Issue::getDescription() {
    return description;
}

int Issue::getPriority() {
    return priority;
}

string Issue::getAssignee(s) {
    return assignee;
}

vector<string> getTags() {
    return tag;
}

string getTagAtPos(int i) {
    return tag.at(i);
}

Status getStatus() {
    return status;
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

void Issue::setAssignee(string newAssignee) {
    assignee = newAssignee;
}

void Issue::addTag(string newTag) {
    tag.push_back(newTag);
}
