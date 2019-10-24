#include <restbed>
#include <nlohmann/json.hpp>
#include "Server.h"


Server::Server(std::string host, int port)
    : resource(std::make_shared<restbed::Resource>()),
      settings(std::make_shared<restbed::Settings>()) {
  resource->set_path(host);
  settings->set_port(port);
}


Server::~Server() {}


void Server::setup() {
  //resource->set_method_handler("GET", get_issues_handler);
  //resource->set_method_handler("POST", create_issue_handler);
  service.publish(resource);
}


void Server::run() {
  service.start(settings);
}


void Server::get_issues_handler(
    const std::shared_ptr<restbed::Session>& session) {
  //nothing
}


void Server::create_issue_handler(
    const std::shared_ptr<restbed::Session>& session) {
  // nothing
}


void Server::create_issue_request(
    const std::shared_ptr<restbed::Session >& session,
    const restbed::Bytes & body) {

  const auto request = session->get_request();
  // for now just get all issues and add filtering later
  nlohmann::json responseJSON = {
    {"status", "ok"},
    {"response", {}}
  };

  for (const auto & iss : system.getIssues()) {
    std::string entry;
    nlohmann::json entryJSON = {
        {"id", iss.getId()},
        {"title", iss.getTitle()},
        {"created", iss.getCreated()},
        {"priority", iss.getPriority()},
    };
    responseJSON["response"].push_back(entryJSON.dump());
  }

  std::string response = responsJSON.dump();
  session->close(restbed::OK, response, {
      ALLOW_ALL,
      { "Content-Length", std::tostring(response.length()) },
      CLOSE_CONNECTION
  });
}









