#include "character/CharacterFactory.hpp"
#include "core/instance/GameInstance.hpp"

Kadopon::GameInstance::GameInstance() {
  // initialize the global registry (within game instance scope)
  Kadopon::Registry registry;

  // create a player
  const Kadopon::Entity player = Character::createCharacter(registry);

  // presumably, things happen here
}