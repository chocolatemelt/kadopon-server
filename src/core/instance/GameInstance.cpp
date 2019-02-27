#include "character/CharacterFactory.hpp"
#include "core/instance/GameInstance.hpp"
#include "spdlog/spdlog.h"

Kadopon::GameInstance::GameInstance() {
  // initialize the global registry (within game instance scope)
  Kadopon::Registry registry;

  // create a player
  const Kadopon::Entity player = Character::createPlayer(registry);

  // presumably, things happen here...
  // since we're still just testing, i'll just keep the game loop code here for now
  // obviously this is temporary and should be handled separately so as not to be tightly coupled
  spdlog::info("kadopon poc starting...");
}
