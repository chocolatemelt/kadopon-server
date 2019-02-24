/**
 * Tests the creation of generic Character entities.
 */
#include "catch.hpp"
#include "character/CharacterFactory.hpp"
#include "misc/Types.hpp"

TEST_CASE("creates a character properly", "[esc][character]") {
  Registry registry;
  Entity e = Character::createCharacter(registry);
  const Life x = registry.get<Life>(e);
  CHECK(x.current == 0);
}
