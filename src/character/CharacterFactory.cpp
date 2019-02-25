#include "character/CharacterFactory.hpp"

Kadopon::Entity Character::createCharacter(Kadopon::Registry &reg) {
  const Kadopon::Entity e = reg.create();
  reg.assign<Attributes::Life>(e);
  reg.assign<Attributes::Mana>(e);
  return e;
}
