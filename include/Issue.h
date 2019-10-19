#ifndef ISSUE_H
#define ISSUE_H

#include <iostream>
#include <string>
#include <vector>
#include "Status.h"

using std::string;
using std::vector;

class Issue {
 public:
    Issue();
    //Issue(string, string, int, int, vector<string>, string, Status);
    //Getters
    string getTitle();
    string getDescription();
    int getPriority();
    int getAssignee();
    vector<string> getTags();
    string getTagAtPos(int i);
    Status getStatus();

    //Setters
    void setTitle(string);
    void setDescription(string);
    void setPriority(int);
    void setAssignee(int);
    void addTag(string);

 private:
    string title;
    string description;
    int priority;
    int assignee;
    vector<string> tags;
    Status status;
};

#endif // ISSUE_H
