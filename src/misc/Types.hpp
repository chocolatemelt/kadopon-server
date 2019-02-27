/**
 * Redefining some types within the source scope for consistency.
 */
#pragma once

#include <entt/entity/registry.hpp>
#include <ws/server_ws.hpp>

namespace Kadopon {
  using Registry = entt::DefaultRegistry;
  using Entity = Registry::entity_type;

  using WSServer = SimpleWeb::SocketServer<SimpleWeb::WS>;
  using WSEndpoint = SimpleWeb::SocketServerBase<boost::asio::basic_stream_socket<boost::asio::ip::tcp> >::Endpoint;
}
