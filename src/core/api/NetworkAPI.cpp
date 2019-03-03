#include <spdlog/spdlog.h>

#include "core/api/NetworkAPI.hpp"

using namespace Kadopon;

NetworkAPI::NetworkAPI() {
  server = std::make_unique<WSServer>();
  server->config.port = 8080;
  poc = &server->endpoint["^/poc/?$"];

  poc->on_message = [](std::shared_ptr<WSServer::Connection> connection, std::shared_ptr<WSServer::InMessage> in_message) {
    auto out_message = in_message->string();
    if(out_message == "echo") {
      spdlog::info("received echo");
    }

    // spdlog::info("{}: {}", connection->remote_endpoint_address(), out_message);
    // spdlog::info("server: echoing");
    //
    // // connection->send is an asynchronous function
    // connection->send(out_message, [](const SimpleWeb::error_code &ec) {
    //   if(ec) {
    //     // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
    //     spdlog::error("server encountered an error: {}", ec.message());
    //   }
    // });
  };

  poc->on_open = [](std::shared_ptr<WSServer::Connection> connection) {
    spdlog::info("server: opened connection with {}", connection->remote_endpoint_address());
  };

  // See RFC 6455 7.4.1. for status codes
  poc->on_close = [](std::shared_ptr<WSServer::Connection> connection, int status, const std::string &) {
    spdlog::info("server: closed connection with {}, status code {:d}", connection->remote_endpoint_address(), status);
  };

  // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
  poc->on_error = [](std::shared_ptr<WSServer::Connection> connection, const SimpleWeb::error_code &ec) {
    // cout << "Server: Error in connection " << connection.get() << ". "
    //      << "Error: " << ec << ", error message: " << ec.message() << endl;
    spdlog::error("server encountered an error in connection with {}: {}",
      connection->remote_endpoint_address(),
      ec.message());
  };

  server_thread = std::make_unique<std::thread>([this]() {
    spdlog::info("kadopon server starting...");
    server->start();
    spdlog::info("kadopon server stopping");
  });
}

NetworkAPI::~NetworkAPI() {
  deinit();
}

void NetworkAPI::init() {
  server_thread->join();
}

void NetworkAPI::deinit() {}
