#ifndef SERVER_H
#define SERVER_H


#include <restbed>
#include <string>


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
   * @param hostAddress The server address.
   */
  Server(std::string hostAddress);
  
  virtual ~Server();
  
  /**
   * Run the server.
   */
  void run();

 private:
  std::string hostAddress;
  std::shared_ptr<restbed::Resource> resource;
  std::shared_ptr<restbed::Settings> settings;
};

#endif
