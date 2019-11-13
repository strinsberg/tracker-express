#ifndef ISSUE_SYSTEM_H
#define ISSUE_SYSTEM_H

#include "User.h"
#include "Issue.h"
#include "Comment.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

/**
 * Holds the Issues, and Users for the issue tracking system.
 *
 * @author Steven Deutekom, Mathew Richards
 * @date Oct 19 2019
 */
class IssueSystem {
 public:
    /**
     * Create a new issue system.
     */
    IssueSystem();

    virtual ~IssueSystem();

    /**
     * Get all the issues.
     *
     * @return the list of issues.
     */
    std::vector<Issue>& getIssues();

    /**
     * Get all the users.
     *
     * @return the list of users.
     */
    std::vector<User>& getUsers();

    /**
     * Get all comments.
     *
     * @return the list of comments.
     */
    std::vector<Comment>& getComments();

    /**
     * Gets an issue by ID.
     *
     * @param id The ID of the issue.
     * @return the issue for the id
     * @throws invalid_argument if the ID does not exist.
     */
    Issue& getIssue(int id);

    /**
     * Get a player by ID.
     *
     * @param id The ID of the player.
     * @return the player with the ID.
     * @throws invalid_argument if the ID does not exist.
     */
    User& getUser(int id);

    /**
     * Get a comment by ID.
     *
     * @param id The id of the comment.
     * @return return the comment by ID.
     * @throws invalid_argument if the ID does not exist.
     */
    Comment& getComment(int id);

    /**
     * Create a new issue.
     *
     * @return the id of the issue.
     */
    int createIssue();

    /**
     * Create a new issue from a JSON string of an issue.
     *
     * @param json An json string of an issue object.
     * @return the issue
     */
    Issue& createIssue(const char* json);

    /**
     * Create a user.
     *
     * @return the id of the user.
     */
    int createUser();

    /**
     * Create a user from a JSON string of a user.
     *
     * @param json An json string of a user object.
     * @return the user.
     */
    User& createUser(const char* json);

    /**
     * Create a new comment.
     *
     * @return the id of the comment.
     */
    int createComment();

    /**
     * Create a new comment from a JSON string of a comment.
     *
     * @param json A json string of a comment object.
     * @return the id of the comment.
     */
    Comment& createComment(const char* json);

    void removeIssue(int id);

    /**
     * Returns a JSON representation of the IssueSystem.
     *
     * @return the system as a JSON object.
     */
    nlohmann::json toJson();

 private:
    std::vector<Issue> issues;
    std::vector<User> users;
    std::vector<Comment> comments;

    int issueCount;
    int commentCount;
    int userCount;

    /**
     * Clean any garbage from a string that is supposed to contain JSON.
     * This is not going to be a perfect fix to the problem of the client
     * sending JSON strings with garbage appended to them. It also does not
     * make sure the string is valid JSON.
     *
     * @param str The string to clean.
     * @return a string that should only contain a JSON object.
     */
    std::string clean(std::string str);
};

#endif
