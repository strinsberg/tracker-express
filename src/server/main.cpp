#include <restbed>
#include <nlohmann/json.hpp>
#include <memory>
#include "Server.h"


int main() {
    Server server("/localhost", 1234);
    server.setup();
    server.run();

    return EXIT_SUCCESS;
}
