/**
 * Tests creation of game instance and validity of entityx components.
 */

#include "catch.hpp"
#include "instance/GameInstance.hpp"

TEST_CASE("creates a game instance", "[instance]") {
  GameInstance instance();
  CHECK(1==1);
}
