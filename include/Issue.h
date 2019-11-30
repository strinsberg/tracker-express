#ifndef ISSUE_H
#define ISSUE_H

#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Status.h"

using std::string;
using std::vector;

/**
* Allows users to create issues with a title, description,
* priority, assignee, and tag.
* @author Lorenzo Bachman-Conrad.
* @date 2019-10-19.
*/
class Issue {
 public:
    /**
    * The default constructor for the Issue class.
    */
    explicit Issue(int);
    /**
    * Getter for the private title string.
    * @return The title string.
    */
    string getTitle();

    /**
    * Getter for the description string.
    * @return The description string.
    */
    string getDescription();

    /**
    * Getter for the priority int.
    * @return The priority int.
    */
    int getPriority();

    /**
    * Getter for the assignee int.
    * @return The assignee int.
    */
    int getAssignee();

    /**
    * Getter for the tags vector.
    * @return The tags vector.
    */
    vector<string> getTags();

    /**
    * Get a tag at a certain vector position.
    * @param i The position in the vector.
    * @return The tag at that vector position.
    */
    string getTagAtPos(int i);

    /**
    * Getter for the Status enum.
    * @return The Status enum.
    */
    Status getStatus();

    /**
    * Getter for IssueId.
    * @return issueId, the ID number of the issue.
    */
    int getId();

    /**
     * Gets the id of the issue creator.
     * @return the id of the creator.
     */
    int getCreator();

    /**
    * Setter for the title.
    * @param newTitle What you would like to name the title.
    */
    void setTitle(string);

    /**
    * Setter for the description.
    * @param newDescription What you would like to name the description.
    */
    void setDescription(string);

    /**
    * Setter for the priority.
    * @param newPriority The new priority you would like to set.
    */
    void setPriority(int);

    /**
    * Setter for the assignee.
    * @param newAssignee The new assignee you would like to set.
    */
    void setAssignee(int);

    /**
    * Adds a tag to the issue by pushing it to the tags vector.
    * @param newTag The new tag you would like to add.
    */
    void addTag(string);

    /**
     * Sets the Id of the creator.
     *
     * @param id The id of the issue creator.
     */
    void setCreator(int id);

    /**
     * Sets the issues status.
     *
     * @param status The status of the issue.
     */
    void setStatus(Status status);

    /**
     * Update the json object for the issue.
     *
     * @param json The string containing json information for the issue.
     */
    void update(std::string json);

    /**
     * Update the json object for the issue.
     *
     * @param json The json fields for the issue.
     */
    void update(nlohmann::json json);

    /**
     * Returns a JSON representation of the Issue.
     *
     * @return the issue in JSON form.
     */
    nlohmann::json toJson();

 private:
    string title;
    string description;
    int priority;
    int assignee;
    int creator;
    int issueId;
    vector<string> tags;
    Status status;
};

#endif
