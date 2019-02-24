/**
 * Tests the creation of generic Character entities.
 */
#include "catch.hpp"
#include "character/CharacterFactory.hpp"
#include "misc/Types.hpp"

TEST_CASE("creates a character properly", "[ecs][character]") {
  Registry registry;
  Entity e = Character::createCharacter(registry);
}
