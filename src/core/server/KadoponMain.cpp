#include <czmq.h>
#include <csignal>
#include <spdlog/spdlog.h>

#include "core/api/NetworkAPI.hpp"
#include "core/instance/GameInstance.hpp"
#include "core/server/KadoponMain.hpp"

using namespace Kadopon;

static int terminate = 0;

void sig_handler(int s) {
  terminate = 1;
  spdlog::info("caught signal {}, terminating", s);
}

int KadoponMain::runner() {
  // single-threaded for now, but we'll see how we can eventually manage multiple instances
  NetworkAPI network;
  network.init();
  zsock_t *pull = zsock_new_pull("inproc://kadopon-network");
  auto main_thread = std::make_unique<std::thread>([pull]() {
    while(true) {
      char *str = zstr_recv(pull);
      spdlog::info("received message: {}", str);
      zstr_free(&str);
    }
  });
  main_thread->detach();

  // im not a bad programmer i promise
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = sig_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);
  while(!terminate);

  // cleanup..?
  zsock_destroy(&pull);
  return 0;
}
