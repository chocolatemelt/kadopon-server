/**
 * Tests the creation of generic Character entities.
 */
#include "catch.hpp"
#include "character/CharacterFactory.hpp"
#include "misc/Types.hpp"

using namespace Kadopon;

TEST_CASE("creates a character properly", "[esc][character]") {
  Registry registry;
  Entity e = Character::createCharacter(registry);
  const Attributes::Life x = registry.get<Attributes::Life>(e);
  CHECK(x.current == 0);
}
