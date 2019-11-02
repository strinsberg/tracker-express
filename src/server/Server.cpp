#include <restbed>
#include <nlohmann/json.hpp>
#include <memory>
#include <string>
#include "Server.h"
#include "Handlers.h"


Server::Server(std::string host, int port)
    : issueResource(std::make_shared<restbed::Resource>()),
      settings(std::make_shared<restbed::Settings>()) {
  issueResource->set_path(host + "/issues");
  userResource->set_path(host + "/users");
  settings->set_port(port);
}


Server::~Server() {}


void Server::setup() {

  // Set issue resources
  issueResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_issues(session, &(this->system));
    });
  issueResource->set_method_handler("POST",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.create_issue(session, &(this->system));
    });

  // Set user resources
  userResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_users(session, &(this->system));
    });
  userResource->set_method_handler("POST",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.create_user(session, &(this->system));
    });

  // Publish resources
  service.publish(issueResource);
}


void Server::run() {
  service.start(settings);
}

