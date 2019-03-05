#include <atomic>
#include <czmq.h>
#include <csignal>
#include <spdlog/spdlog.h>

#include "core/api/NetworkAPI.hpp"
#include "core/instance/GameInstance.hpp"
#include "core/server/KadoponMain.hpp"

using namespace Kadopon;

// not sure where to put this in actual code, but this works as a proof-of-concept
static std::atomic<bool> terminate { false };

void sig_handler(int s) {
  terminate = true;
  spdlog::info("caught signal {}, terminating", s);
}

int KadoponMain::runner() {
  NetworkAPI network;
  network.init();

  // this really should start in a separate instance, not the runner class
  zsock_t *pull = zsock_new_pull("inproc://kadopon-network");
  auto main_thread = std::make_unique<std::thread>([pull]() {
    while(!terminate) {
      char *str = zstr_recv(pull);
      spdlog::info("received message: {}", str);
      zstr_free(&str);
    }
  });

  // this runs some custom code (i.e. terminate) upon receiving SIGINT
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = sig_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);
  while(!terminate);

  // cleanup..?
  network.deinit();
  zsock_destroy(&pull);
  return 0;
}
