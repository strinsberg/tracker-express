#include <iostream>
#include <string>
#include "status.h"

class Issue {

public:
    //Getters
    string getTitle();
    string getDescription();
    int getPriority();
    string getAssignee();

    //Setters
    void setTitle();
    void setDescription();
    void setPriority();
    void setAssignee();

private:
    string title;
    string description;
    int priority;
    string assignee;
    vector<string> tag;
    Status status;


};
