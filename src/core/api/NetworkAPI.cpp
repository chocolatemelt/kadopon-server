#include <spdlog/spdlog.h>

#include "core/api/NetworkAPI.hpp"

using namespace Kadopon;

NetworkAPI::NetworkAPI() {
  server = std::make_unique<WSServer>();
  server->config.port = 8080;
  poc = &server->endpoint["^/poc/?$"];
  server_thread = std::make_unique<std::thread>([this]() {
    spdlog::info("kadopon server starting...");
    server->start();
  });
}

NetworkAPI::~NetworkAPI() {
  deinit();
}

void NetworkAPI::init() {
  server_thread->join();
}

void NetworkAPI::deinit() {}
