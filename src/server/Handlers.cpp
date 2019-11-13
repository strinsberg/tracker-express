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


// Issues //

void Handlers::get_issues(const std::shared_ptr<restbed::Session>& session,
                          IssueSystem* system) {
  const auto request = session->get_request();

  nlohmann::json result = {
    {"status", "ok"},
    {"response", {}}
  };

  if (request->has_query_parameter("id")) {
      int id = request->get_query_parameter<int>("id", -1);

      try {
        Issue& iss = system->getIssue(id);
        result["response"] = iss.toJson().dump();
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

  } else {
      for (auto & iss : system->getIssues()) {
        std::string json(iss.toJson().dump());
        result["response"].push_back(json);
      }
  }

  std::string response = result.dump();
  std::cout << "GET: Issues: " << response << std::endl;
  std::cout << std::endl;

  closeSessionOk(session, response);
}

void Handlers::post_issue(const std::shared_ptr<restbed::Session>& session,
                            IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  session->fetch(content_length,
      [this, system, request](const std::shared_ptr<restbed::Session>& session,
          const restbed::Bytes& body) {
    nlohmann::json result = {
      {"status", "ok"},
      {"response", ""}
    };

    const char* bodyInfo = reinterpret_cast<const char*>(body.data());

    if (request->has_query_parameter("id")) {
      int id = request->get_query_parameter<int>("id", -1);

      try {
        Issue& iss = system->getIssue(id);
        iss.update(bodyInfo);
        result["response"] = iss.toJson().dump();
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

    } else {
        Issue& iss = system->createIssue(bodyInfo);
        result["response"] = iss.toJson().dump();
    }

    std::string response = result.dump();

    std::cout << "POST: Issue: " << response << std::endl;
    std::cout << "Number of Issues: " << system->getIssues().size();
    std::cout << std::endl << std::endl;

    this->closeSessionOk(session, response);
    });
}

void Handlers::delete_issue(const std::shared_ptr<restbed::Session>& session,
                            IssueSystem* system) {
    const auto request = session->get_request();

    int id = request->get_query_parameter<int>("id", -1);

    nlohmann::json result = {
      {"status", "fail"},
      {"response", "invalid id"}
    };

    try {
        Issue& iss = system->getIssue(id);
        result["response"] = iss.toJson().dump();
        result["status"] = "ok";
        system->removeIssue(id);
    } catch (const std::invalid_argument& e) {}

    std::string response = result.dump();

    std::cout << "DELETE: issue: " << id << std::endl;
    std::cout << response << std::endl << std::endl;

    closeSessionOk(session, response);
}


// Users //

void Handlers::get_users(const std::shared_ptr<restbed::Session>& session,
                         IssueSystem* system) {
  const auto request = session->get_request();

  nlohmann::json result = {
    {"status", "ok"},
    {"response", {}}
  };

  if (request->has_query_parameter("id")) {
      int id = request->get_query_parameter<int>("id", -1);

      try {
        User& user = system->getUser(id);
        result["response"] = user.toJson().dump();
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

  } else {
      for (auto & user : system->getUsers()) {
        std::string json(user.toJson().dump());
        result["response"].push_back(json);
      }
  }

  std::string response = result.dump();
  std::cout << "GET: Users: " << response << std::endl;
  std::cout << std::endl;

  closeSessionOk(session, response);
}

void Handlers::post_user(const std::shared_ptr<restbed::Session>& session,
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

void Handlers::delete_user(const std::shared_ptr<restbed::Session>& session,
                           IssueSystem* system) {
    const auto request = session->get_request();

    int id = request->get_path_parameter<int>("id", -1);

    nlohmann::json result = {
      {"status", "fail"},
      {"response", "invalid id"}
    };

    try {
        User& user = system->getUser(id);
        system->removeUser(id);
        result["response"] = user.toJson().dump();
        result["status"] = "ok";
    } catch (const std::invalid_argument& e) {}

    std::string response = result.dump();

    std::cout << "DELETE: user: " << id << std::endl;
    std::cout << response << std::endl << std::endl;

    closeSessionOk(session, response);
}


// Private //

void Handlers::closeSessionOk(const std::shared_ptr<restbed::Session>& session,
        const std::string& response) {
    session->close(restbed::OK, response,
    {
      ALLOW_ALL,
      {
        "Content-Length", std::to_string(response.length())
      },
      CLOSE_CONNECTION
    });
}

