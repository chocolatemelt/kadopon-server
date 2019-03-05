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
  // im not a bad programmer i promise
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = sig_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);
  while(!terminate);
  return 0;
}
