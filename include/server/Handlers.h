#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
#include <memory>
#include "IssueSystem.h"


class Handlers {
 public:
  void get_issues(const std::shared_ptr<restbed::Session>& session,
                  IssueSystem* system);
  void create_issue(const std::shared_ptr<restbed::Session>& session,
                    IssueSystem* system);
  void get_users(const std::shared_ptr<restbed::Session>& session,
                  IssueSystem* system);
  void create_user(const std::shared_ptr<restbed::Session>& session,
                    IssueSystem* system);
 private:
  void closeSessionOk(const std::shared_ptr<restbed::Session>& session,
                      const std::string& response);
};

#endif
