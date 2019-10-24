#ifndef HANDLERS_H
#define HANDLERS_H

#include "IssueSystem.h"


class Handlers {
 public:
  void get_issues(const std::shared_ptr<restbed::Session>& session,
                  IssueSystem& system);
  void create_issue(const std::shared_ptr<restbed::Session>& session,
                    const restbed::Bytes& body,
                    IssueSystem& system);
};

#endif
