#ifndef ISSUE_SYSTEM_H
#define ISSUE_SYSTEM_H

#include <string>
#include <vector>
#include "User.h"
#include "Issue.h"
#include "Comment.h"

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
   * Create a user.
   *
   * @return the id of the user.
   */
  int createUser();

  /**
   * Create a new comment.
   *
   * @return the id of the comment.
   */
  int createComment();

 private:
  std::vector<Issue> issues;
  std::vector<User> users;
  std::vector<Comment> comments;

  int issueCount;
  int commentCount;
  int userCount;
};

#endif
