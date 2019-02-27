#include "character/CharacterFactory.hpp"

using namespace Kadopon;

static Entity initCharacter(Kadopon::Registry &reg) {
  const Kadopon::Entity e = reg.create();
  reg.assign<Attributes::Life>(e);
  reg.assign<Attributes::Mana>(e);
  return e;
}

Entity Character::createPlayer(Kadopon::Registry &reg) {
  const Kadopon::Entity e = initCharacter(reg);
  return e;
}
