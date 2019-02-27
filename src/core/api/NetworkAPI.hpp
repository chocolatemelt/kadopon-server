/**
 * Internal network API.
 */
#pragma once

#include <memory>

#include "core/api/KadoponAPI.hpp"
#include "misc/Types.hpp"

namespace Kadopon {
  class NetworkAPI : public KadoponAPI {
  public:
    NetworkAPI();
    ~NetworkAPI();

    void init();
    void deinit();

  private:
    std::unique_ptr<WSServer> server;

    WSEndpoint *poc; // PROOF OF CONCEPT ENDPOINT. wrap this later.
    std::unique_ptr<std::thread> server_thread;
  };
}
