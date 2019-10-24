#include <restbed>
#include <nlohmann/json.hpp>
#include "Server.h"
#include "Handlers.h"

#define ALLOW_ALL { "Access-Control-Allow-Origin", "*" }
#define CLOSE_CONNECTION { "Connection", "close" }


Server::Server(std::string host, int port)
    : resource(std::make_shared<restbed::Resource>()),
      settings(std::make_shared<restbed::Settings>()) {
  resource->set_path(host);
  settings->set_port(port);
}


Server::~Server() {}


void Server::setup() {
  resource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_issues(session, this->system);
    });
  //resource->set_method_handler("POST", &create_issue_handler);
  service.publish(resource);
}


void Server::run() {
  service.start(settings);
}


void Server::get_issues_handler(
    const std::shared_ptr<restbed::Session>& session) {

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


void Server::create_issue_handler(
    const std::shared_ptr<restbed::Session>& session) {
}


void Server::create_issue_request(
    const std::shared_ptr<restbed::Session >& session,
    const restbed::Bytes & body) {
}









