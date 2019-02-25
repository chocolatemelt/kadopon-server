#include "core/instance/GameInstance.hpp"
#include "core/server/KadoponMain.hpp"

using namespace Kadopon;

int KadoponMain::runner() {
  // single-threaded for now, but we'll see how we can eventually manage multiple instances
  GameInstance main;
  return 0;
}
