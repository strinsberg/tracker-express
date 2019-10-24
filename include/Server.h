#ifndef SERVER_H
#define SERVER_H


#include <restbed>
#include <string>
#include <memory>
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

 protected:
  void get_issues_handler(const std::shared_ptr<restbed::Session>& session);
  void create_issue_handler(const std::shared_ptr<restbed::Session>& session);
  void create_issue_request(const std::shared_ptr<restbed::Session >& session,
                            const restbed::Bytes & body);

 private:
  IssueSystem system;
  std::shared_ptr<restbed::Resource> resource;
  std::shared_ptr<restbed::Settings> settings;
  restbed::Service service;
};

#endif
