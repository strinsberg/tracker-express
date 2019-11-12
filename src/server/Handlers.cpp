#include <restbed>
#include <nlohmann/json.hpp>
#include <string>
#include <memory>
#include <iostream>
#include "Handlers.h"
#include "IssueSystem.h"
#include "Status.h"


#define ALLOW_ALL { "Access-Control-Allow-Origin", "*" }
#define CLOSE_CONNECTION { "Connection", "close" }


void Handlers::get_issues(const std::shared_ptr<restbed::Session>& session,
                          IssueSystem* system) {
  const auto request = session->get_request();
  // for now just get all issues and add filtering later
  nlohmann::json responseJSON = {
    {"status", "ok"},
    {"response", {}}
  };

  std::cout << "GET: Issues:" << std::endl;
  for (auto & iss : system->getIssues()) {
    std::string json(iss.toJson().dump());
    responseJSON["response"].push_back(json);
    std::cout << json << std::endl;
  }

  std::string response = responseJSON.dump();
  std::cout << std::endl;

  closeSessionOk(session, response);
}

void Handlers::create_issue(const std::shared_ptr<restbed::Session>& session,
                            IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  session->fetch(content_length,
      [this, system](const std::shared_ptr<restbed::Session>& session,
          const restbed::Bytes& body) {
    Issue& iss = system->createIssue(reinterpret_cast<const char*>(body.data()));

    nlohmann::json result = {
      {"status", "ok"},
      {"response", iss.toJson().dump()}
    };
    std::string response = result.dump();

    std::cout << "POST: Issue: " << response << std::endl;
    std::cout << "Number of Issues: " << system->getIssues().size();
    std::cout << std::endl << std::endl;

    this->closeSessionOk(session, response);
    });
}


void Handlers::get_users(const std::shared_ptr<restbed::Session>& session,
                         IssueSystem* system) {
  nlohmann::json responseJSON = {
    {"status", "ok"},
    {"response", {}}
  };

  std::cout << "GET: Users:" << std::endl;
  for (auto & user : system->getUsers()) {
    std::string json(user.toJson().dump());
    responseJSON["response"].push_back(json);
    std::cout << json << std::endl;
  }

  std::string response = responseJSON.dump();
  std::cout << std::endl;

  closeSessionOk(session, response);
}

void Handlers::create_user(const std::shared_ptr<restbed::Session>& session,
                           IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  // Fetch with lambda for dealing with the request
  session->fetch(content_length,
      [this, system](const std::shared_ptr<restbed::Session>& session,
          const restbed::Bytes& body) {
    User& user = system->createUser(reinterpret_cast<const char*>(body.data()));

    // Create and send response
    nlohmann::json result = {
      {"status", "ok"},
      {"response", user.toJson().dump()}
    };
    std::string response = result.dump();

    std::cout << "POST: User: " << response << std::endl;
    std::cout << "Number of Users: " << system->getUsers().size();
    std::cout << std::endl << std::endl;

    this->closeSessionOk(session, response);
    });
}


// Private //

void Handlers::closeSessionOk(const std::shared_ptr<restbed::Session>& session,
        std::string& response) {
    session->close(restbed::OK, response,
    {
      ALLOW_ALL,
      {
        "Content-Length", std::to_string(response.length())
      },
      CLOSE_CONNECTION
    });
}

