#include <restbed>
#include <nlohmann/json.hpp>
#include "Server.h"
#include "Handlers.h"


Server::Server(std::string host, int port)
    : issueResource(std::make_shared<restbed::Resource>()),
      settings(std::make_shared<restbed::Settings>()) {
  issueResource->set_path(host + "/issues");
  settings->set_port(port);
}


Server::~Server() {}


void Server::setup() {
  issueResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_issues(session, this->system);
    });
  issueResource->set_method_handler("POST",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.create_issue(session, this->system);
    });
  service.publish(issueResource);
}


void Server::run() {
  service.start(settings);
}

