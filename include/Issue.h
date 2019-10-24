#ifndef ISSUE_H
#define ISSUE_H

#include <iostream>
#include <string>
#include <vector>
#include "Status.h"

using std::string;
using std::vector;
/**
* Allows users to create issues with a title, description,
* priority, assignee, and tag.
* @author Lorenzo Bachman-Conrad
* @date 2019-10-19
*/
class Issue {
 public:
    /**
    * @brief The default constructor for the Issue class.
    */
    Issue();
    //Issue(string, string, int, int, vector<string>, string, Status);
    //Getters
    /**
    * @brief Getter for the private title string
    * @return The title string
    */
    string getTitle();
    /**
    * @brief Getter for the description string
    * @return The description string
    */
    string getDescription();
    /**
    * @brief Getter for the priority int
    * @return The priority int
    */
    int getPriority();
    /**
    * @brief Getter for the assignee int
    * @return The assignee int
    */
    int getAssignee();
    /**
    * @brief Getter for the tags vector
    * @return The tags vector
    */
    vector<string> getTags();
    /**
    * @brief Get a tag at a certain vector position
    * @param i The position in the vector
    * @return The tag at that vector position
    */
    string getTagAtPos(int i);
    /**
    * @brief Getter for the Status enum
    * @return The Status enum
    */
    Status getStatus();

    //Setters
    /**
    * @brief Setter for the title
    * @param newTitle What you would like to name the title
    */
    void setTitle(string);
    /**
    * @brief Setter for the description
    * @param newDescription What you would like to name the description
    */
    void setDescription(string);
    /**
    * @brief Setter for the priority
    * @param newPriority The new priority you would like to set.
    */
    void setPriority(int);
    /**
    * @brief Setter for the assignee
    * @param newAssignee The new assignee you would like to set.
    */
    void setAssignee(int);
    /**
    * @brief Adds a tag to the issue by pushing it to the tags vector
    * @param newTag The new tag you would like to add.
    */
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
