#include "server_ws.hpp"
//using namespace std;
using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;

int main() {
  WsServer server;
  server.config.port = 8080;
  auto &poc = server.endpoint["poc"];

  poc.on_message = [](std::shared_ptr<WsServer::Connection> connection, std::shared_ptr<WsServer::Message> message) {
    auto message_str = message->string();
    std::cout << "Server: Message received: \"" << message_str << "\" from " << connection.get() << std::endl;

    std::cout << "Server: Sending message 'Welcome to Kadopon' to " << connection.get() << std::endl;
    auto send_stream = std::make_shared<WsServer::SendStream>();
    *send_stream << "Welcome to Kadopon";

    // connection->send is an asynchronous function
    connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
      if (ec) {
        std::cout << "Server: Error sending message. " <<
        "Error: " << ec << ", error message: " << ec.message() << std::endl;
      }
    });
  };

  poc.on_open = [](std::shared_ptr<WsServer::Connection> connection) {
    std::cout << "Server: Opened connection " << connection.get() << std::endl;
  };

  // See RFC 6455 7.4.1. for status codes
  poc.on_close = [](std::shared_ptr<WsServer::Connection> connection, int status, const std::string & /*reason*/) {
    std::cout << "Server: Closed connection " << connection.get() << " with status code " << status << std::endl;
  };

  // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
  poc.on_error = [](std::shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
    std::cout << "Server: Error in connection " << connection.get() << ". "
         << "Error: " << ec << ", error message: " << ec.message() << std::endl;
  };
};