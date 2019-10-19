#include <iostream>
#include <string>
#include <vector>
#include "include/status.h"

using std::string;
using std::vector;

class Issue {
 public:
    //Getters
    string getTitle();
    string getDescription();
    int getPriority();
    string getAssignee();
    vector<string> getTags();
    string getTagAtPos(int i);
    Status getStatus();

    //Setters
    void setTitle(string);
    void setDescription(string);
    void setPriority(int);
    void setAssignee(string);
    void addTag(string);

 private:
    string title;
    string description;
    int priority;
    string assignee;
    vector<string> tag;
    Status status;
};
