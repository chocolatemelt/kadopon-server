#include "character/CharacterFactory.hpp"
#include "instance/GameInstance.hpp"

GameInstance::GameInstance() {
  Registry registry;
  const Entity player = Character::createCharacter(registry);
}
