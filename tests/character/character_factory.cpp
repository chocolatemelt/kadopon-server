/**
 * Tests the creation of generic Character entities.
 */
#include "catch.hpp"
#include "character/CharacterFactory.hpp"
#include "misc/Types.hpp"

using namespace Kadopon;

TEST_CASE("creates a player properly", "[esc][character]") {
  Registry registry;
  Entity e = Character::createPlayer(registry);
  const Attributes::Life x = registry.get<Attributes::Life>(e);
  CHECK(x.current == 0);
}
