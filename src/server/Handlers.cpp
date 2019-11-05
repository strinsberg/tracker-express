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
    nlohmann::json entryJSON = {
        {"id", iss.getId()},
        {"title", iss.getTitle()},
        {"created", iss.getCreator()},
        {"priority", iss.getPriority()},
    };
    responseJSON["response"].push_back(entryJSON.dump());
    std::cout << entryJSON.dump() << std::endl;
  }

  std::string response = responseJSON.dump();

  std::cout << std::endl;

  session->close(restbed::OK, response,
    { ALLOW_ALL,
      { "Content-Length", std::to_string(response.length()) },
    CLOSE_CONNECTION });
}

void Handlers::create_issue(const std::shared_ptr<restbed::Session>& session,
                            IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  session->fetch(content_length,
      [system](const std::shared_ptr<restbed::Session>& session,
          const restbed::Bytes& body) {
    int id = system->createIssue();
    Issue& iss = system->getIssue(id);

    std::cout << "Body: " << body.data() << std::endl;
    auto data = nlohmann::json::parse(body.data());

    iss.setTitle(data["title"]);
    iss.setDescription(data["description"]);
    iss.setAssignee(data["assignee"]);
    iss.setCreator(data["creator"]);
    iss.setPriority(data["priority"]);
    if (iss.getAssignee() == -1)
        iss.setStatus(Status::NEW);
    else
        iss.setStatus(Status::ASSIGNED);

    nlohmann::json result = {
      {"status", "ok"},
      {"response", data}
    };
    std::string response = result.dump();

    std::cout << "POST: Issue: " << response << std::endl;
    std::cout << "Number of Issues: " << system->getIssues().size();
    std::cout << std::endl << std::endl;

    session->close(restbed::OK, response, {
      ALLOW_ALL, {
        "Content-Length", std::to_string(response.length())
      },
      CLOSE_CONNECTION
    });
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
    nlohmann::json entryJSON = {
        {"id", user.getId()},
        {"name", user.getName()},
        {"blurb", user.getBlurb()},
        {"pic", user.getPictureNum()},
    };
    responseJSON["response"].push_back(entryJSON.dump());
    std::cout << entryJSON.dump() << std::endl;
  }

  std::string response = responseJSON.dump();

  std::cout << std::endl;

  session->close(restbed::OK, response,
    { ALLOW_ALL,
      { "Content-Length", std::to_string(response.length()) },
    CLOSE_CONNECTION });
}

void Handlers::create_user(const std::shared_ptr<restbed::Session>& session,
                           IssueSystem* system) {
  const auto request = session->get_request();
  size_t content_length = request->get_header("Content-Length", 0);

  // Fetch with lambda for dealing with the request
  session->fetch(content_length,
      [system](const std::shared_ptr<restbed::Session>& session,
          const restbed::Bytes& body) {
    int id = system->createUser();
    User& user = system->getUser(id);

    nlohmann::json data;
    std::string temp_body(reinterpret_cast<const char*>(body.data()));

    // Hack to remove extra info from post body
    // Don't know why it is there, but it should be fixed eventually
    std::cout << "Body: " << temp_body.substr(0, temp_body.length() - 8);
    std::cout << std::endl;
    if (temp_body.find("/users'") != std::string::npos)
        data = nlohmann::json::parse(
          temp_body.substr(0, temp_body.length() - 8));
    else
        data = nlohmann::json::parse(temp_body);

    // Setup user object
    user.setName(data["name"]);
    user.setBlurb(data["blurb"]);
    user.setPictureNum(data["pic"]);

    // Create and send response
    nlohmann::json result = {
      {"status", "ok"},
      {"response", data}
    };
    std::string response = result.dump();

    std::cout << "POST: User: " << response << std::endl;
    std::cout << "Number of Users: " << system->getUsers().size();
    std::cout << std::endl << std::endl;

    session->close(restbed::OK, response, {
      ALLOW_ALL, {
        "Content-Length", std::to_string(response.length())
      },
      CLOSE_CONNECTION
    });
  });
}
