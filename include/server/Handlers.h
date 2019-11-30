#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
#include <memory>
#include "IssueSystem.h"

/**
 * Contains handlers to handle handled API requests :).
 *
 * @author Steven Deutekom, Mathew Richards
 * @date 2019-11
 */
class Handlers {
 public:
    /**
     * Returns a JSON representation of the Issue.
     *
     * @param session The restbed session.
     * @param system The IssueSystem.
     */
  void get_issues(const std::shared_ptr<restbed::Session>& session,
                  IssueSystem* system);
    /**
     * Create or update an Issue in response to an API call
     *
     * @param session The restbed session.
     * @param system The IssueSystem
     */
  void post_issue(const std::shared_ptr<restbed::Session>& session,
                  IssueSystem* system);
    /**
     * Returns a JSON representation of the Users.
     *
     * @param session The restbed session.
     * @param system The IssueSystem.
     */
  void get_users(const std::shared_ptr<restbed::Session>& session,
                 IssueSystem* system);
    /**
     * Create or update a User in response to an API call.
     *
     * @param session The restbed session.
     * @param system The IssueSystem.
     */
  void post_user(const std::shared_ptr<restbed::Session>& session,
                 IssueSystem* system);
    /**
     * Returns a JSON representation of the Issue.
     *
     * @param session The restbed session.
     * @param system The IssueSystem.
     */
  void get_comments(const std::shared_ptr<restbed::Session>& session,
                    IssueSystem* system);
    /**
     * Returns a JSON representation of the Comment.
     *
     * @param session The restbed session.
     * @param system The IssueSystem.
     */
  void post_comment(const std::shared_ptr<restbed::Session>& session,
                    IssueSystem* system);

 private:
  void closeSessionOk(const std::shared_ptr<restbed::Session>& session,
                      const std::string& response);
};

#endif
