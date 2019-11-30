#include <restbed>
#include <nlohmann/json.hpp>
#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include "Server.h"
#include "Handlers.h"


Server::Server(std::string host, int port)
    : issueResource(std::make_shared<restbed::Resource>()),
      userResource(std::make_shared<restbed::Resource>()),
      commentResource(std::make_shared<restbed::Resource>()),
      settings(std::make_shared<restbed::Settings>()) {
  issueResource->set_path(host + "/issues");
  userResource->set_path(host + "/users");
  commentResource->set_path(host + "/comments");
  settings->set_port(port);
}


Server::~Server() {
  save();
}


void Server::setup() {
  // Set issue resources
  issueResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_issues(session, &(this->system));
    });
  issueResource->set_method_handler("POST",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.post_issue(session, &(this->system));
    });

  // Set user resources
  userResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_users(session, &(this->system));
    });
  userResource->set_method_handler("POST",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.post_user(session, &(this->system));
    });

  // Set comment resources
  commentResource->set_method_handler("GET",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.get_comments(session, &(this->system));
    });
  commentResource->set_method_handler("POST",
    [this](const std::shared_ptr<restbed::Session>& session) {
      this->handler.post_comment(session, &(this->system));
    });

  // Publish resources
  service.publish(issueResource);
  service.publish(userResource);
  service.publish(commentResource);

  // load current issue system state
  std::string fileContents;
  std::fstream file;
  file.open("serverState.json", std::fstream::in);
  if (file.is_open()) {
      char c;
      while (file.get(c))
         fileContents.push_back(c);
      file.close();
      std::cout << fileContents << std::endl;
      system.deserialize(fileContents);
      std::cout << "TrackEX: Loaded previous server state\n\n" << std::endl;
  } else {
      std::cout << "TrackEx: Could not load previous state";
      std::cout << " or there was no save file.\n\n";
  }
}


void Server::run() {
  service.start(settings);
}

void Server::save() {
    // save the server contents
    std::string state(system.serialize());
    std::fstream file;
    file.open("serverState.json", std::fstream::out);
    if (file.is_open()) {
        file << state;
        std::cout << "TrackEx: Server state saved.\n\n";
    } else {
        std::cout << "TrackEx: Error saving server state.\n\n";
    }
}

