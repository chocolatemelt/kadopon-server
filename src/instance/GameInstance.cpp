#include "character/CharacterFactory.hpp"
#include "instance/GameInstance.hpp"

GameInstance::GameInstance() {
  Kadopon::Registry registry;
  const Kadopon::Entity player = Character::createCharacter(registry);
}
