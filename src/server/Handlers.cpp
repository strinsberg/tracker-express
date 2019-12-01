#include <restbed>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Handlers.h"
#include "IssueSystem.h"
#include "Status.h"
#include "Issue.h"
#include "User.h"
#include "Comment.h"

#define ALLOW_ALL { "Access-Control-Allow-Origin", "*" }
#define CLOSE_CONNECTION { "Connection", "close" }


// Issues ////////////////////////////////////////////////////////////////

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
        result["response"] = iss.toJson();

        // Delete the issue (because DELETE didn't work)
        if (request->has_query_parameter("delete")) {
            system->removeIssue(id);
            }
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

  } else if (request->has_query_parameter("filter")) {
      int pri = request->get_query_parameter<int>("priority", -1);
      std::string tag = request->get_query_parameter("tag", "");
      int stat = request->get_query_parameter<int>("status", -1);

      std::vector<Issue> issues = system->filterIssues(pri, tag, stat);
      for (auto & iss : issues)
          result["response"].push_back(iss.toJson());

  } else {
      for (auto & iss : system->getIssues()) {
        result["response"].push_back(iss.toJson());
      }
  }

  std::string response = result.dump(4);
  std::cout << "=== GET Issues ===========================================";
  std::cout <<std::endl << response << std::endl;
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
        iss.update(system->clean(bodyInfo));
        result["response"] = iss.toJson();
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

    } else {
        Issue& iss = system->createIssue(bodyInfo);
        result["response"] = iss.toJson();
    }

    std::string response = result.dump(4);

    std::cout << "=== POST Issue =========================================";
    std::cout << std::endl << response << std::endl;
    std::cout << "Number of Issues: " << system->getIssues().size();
    std::cout << std::endl << std::endl;

    this->closeSessionOk(session, response);
  });
}


// Users /////////////////////////////////////////////////////////////////

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
        result["response"] = user.toJson();
        if (request->has_query_parameter("delete")) {
            system->removeUser(id);
            }
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

  } else {
      for (auto & user : system->getUsers()) {
        result["response"].push_back(user.toJson());
      }
  }

  std::string response = result.dump(4);
  std::cout << "=== GET Users ============================================";
  std::cout << std::endl << response << std::endl;
  std::cout << std::endl;

  closeSessionOk(session, response);
}

void Handlers::post_user(const std::shared_ptr<restbed::Session>& session,
                           IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  // Fetch with lambda for dealing with the request
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
        User& user = system->getUser(id);
        user.update(system->clean(bodyInfo));
        result["response"] = user.toJson();
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

    } else {
        User& user = system->createUser(bodyInfo);
        result["response"] = user.toJson();
    }

    std::string response = result.dump(4);

    std::cout << "=== POST User ==========================================";
    std::cout << std::endl << response << std::endl;
    std::cout << "Number of Users: " << system->getUsers().size();
    std::cout << std::endl << std::endl;

    this->closeSessionOk(session, response);
  });
}

// COMMENTS //////////////////////////////////////////////////////////////

void Handlers::get_comments(const std::shared_ptr<restbed::Session>& session,
                IssueSystem* system) {
  const auto request = session->get_request();

  nlohmann::json result = {
    {"status", "ok"},
    {"response", {}}
  };

  if (request->has_query_parameter("id")) {
      int id = request->get_query_parameter<int>("id", -1);

      try {
        Comment& com = system->getComment(id);
        result["response"] = com.toJson();
        if (request->has_query_parameter("delete"))
            system->removeComment(id);
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

  } else if (request->has_query_parameter("issue")) {
      int id = request->get_query_parameter<int>("issue", -1);

      try {
        std::vector<Comment> coms = system->filterComments(id);
        std::cout << "size: " << coms.size() << std::endl;
        for (auto & com : coms) {
          std::cout << "ID: " << com.getId() << std::endl;
          result["response"].push_back(com.toJson());
        }
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid issue id";
      }

  } else {
      for (auto & com : system->getComments()) {
        result["response"].push_back(com.toJson());
      }
  }

  std::string response = result.dump(4);
  std::cout << "=== GET Comments ===========================================";
  std::cout <<std::endl << response << std::endl;
  std::cout << std::endl;

  closeSessionOk(session, response);
}

void Handlers::post_comment(const std::shared_ptr<restbed::Session>& session,
                IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  // Fetch with lambda for dealing with the request
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
        Comment& com = system->getComment(id);
        com.update(system->clean(bodyInfo));
        result["response"] = com.toJson();
      } catch (const std::invalid_argument& e) {
        result["status"] = "fail";
        result["response"] = "invalid id";
      }

    } else {
        Comment& com = system->createComment(bodyInfo);
        result["response"] = com.toJson();
    }

    std::string response = result.dump(4);

    std::cout << "=== POST Comment ==========================================";
    std::cout << std::endl << response << std::endl;
    std::cout << "Number of Comments: " << system->getComments().size();
    std::cout << std::endl << std::endl;

    this->closeSessionOk(session, response);
  });
}


// Private ///////////////////////////////////////////////////////////////

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

