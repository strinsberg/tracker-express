#include <restbed>
#include <nlohmann/json.hpp>
#include "Handlers.h"
#include "IssueSystem.h"


#define ALLOW_ALL { "Access-Control-Allow-Origin", "*" }
#define CLOSE_CONNECTION { "Connection", "close" }


void Handlers::get_issues(const std::shared_ptr<restbed::Session>& session,
                          IssueSystem& system) {
  const auto request = session->get_request();
  // for now just get all issues and add filtering later
  nlohmann::json responseJSON = {
    {"status", "ok"},
    {"response", {}}
  };

  for (auto & iss : system.getIssues()) {
    std::string entry;
    nlohmann::json entryJSON = {
        {"id", iss.getId()},
        {"title", iss.getTitle()},
        {"created", iss.getCreator()},
        {"priority", iss.getPriority()},
    };
    responseJSON["response"].push_back(entryJSON.dump());
  }

  std::string response = responseJSON.dump();
  session->close(restbed::OK, response, {
      ALLOW_ALL,
      { "Content-Length", std::to_string(response.length()) },
      CLOSE_CONNECTION
  });
}
