#include <signal.h>
#include <restbed>
#include <nlohmann/json.hpp>
#include <memory>
#include "Server.h"

Server* server;

void handler(int num) {
    std::cout << "Shutting down server ...." << std::endl;
    delete server;
    exit(EXIT_SUCCESS);
}

int main() {
    // Handle keyboard interupt to properly shut down the server
    signal(SIGINT, handler);

    // Create and run server
    server = new Server("/trackEx", 1234);
    server->setup();
    server->run();

    delete server;

    return EXIT_SUCCESS;
}
