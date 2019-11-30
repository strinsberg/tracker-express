#ifndef SERVER_H
#define SERVER_H


#include <restbed>
#include <string>
#include <memory>
#include "Handlers.h"
#include "IssueSystem.h"


/**
 * The RESTful server.
 *
 * @author Steven Deutekom
 * @date oct 23 2019
 */
class Server {
 public:
  /**
   * Create a new REST server.
   *
   * @param host The server address.
   * @param port The port for the server.
   */
  Server(std::string host, int port);

  virtual ~Server();

  /**
   * Setup server endpoints and settings.
   */
  void setup();

  /**
   * Run the server.
   */
  void run();

  void save();

 private:
  IssueSystem system;
  Handlers handler;
  std::shared_ptr<restbed::Resource> issueResource;
  std::shared_ptr<restbed::Resource> userResource;
  std::shared_ptr<restbed::Resource> commentResource;
  std::shared_ptr<restbed::Settings> settings;
  restbed::Service service;
};

#endif
