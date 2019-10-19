#include <restbed>
#include <nlohmann/json.hpp>
#include <memory>


int main() {
    auto resource = std::make_shared<restbed::Resource>();
    resource->set_path("/trackexp");
    //resource->set_method_handler("GET", );

    auto settings = std::make_shared<restbed::Settings>();
    settings->set_port(1234);

    restbed::Service service;
    service.publish(resource);

    service.start(settings);
    return EXIT_SUCCESS;
}
