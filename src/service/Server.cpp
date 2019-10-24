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
