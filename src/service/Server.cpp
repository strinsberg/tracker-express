#include <restbed>
#include <nlohmann/json.hpp>
#include "Server.h"
#include "Handlers.h"


Server::Server(std::string host, int port)
    : IssueResource(std::make_shared<restbed::Resource>()),
      settings(std::make_shared<restbed::Settings>()) {
  IssueResource->set_path(host + "/issues");
  settings->set_port(port);
}


Server::~Server() {}


void Server::setup() {
  IssueResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_issues(session, this->system);
    });
  //resource->set_method_handler("POST");
  service.publish(IssueResource);
}


void Server::run() {
  service.start(settings);
}

