#include "character/CharacterFactory.hpp"

Entity Character::createCharacter(Registry &reg) {
  const Entity e = reg.create();
  reg.assign<Attributes::Life>(e);
  reg.assign<Attributes::Mana>(e);
  return e;
}
