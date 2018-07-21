/**
 * Tests character creation and relevant functions.
 */

#include "catch.hpp"
#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entities/Character.hpp"
#include "entityx/entityx.h"
#include "instance/GameInstance.hpp"

TEST_CASE("creates a character", "[instance]") {
  GameInstance instance;

  Character ranger(instance.entities.create());
  CHECK(0 == ranger.component<Life>()->maximum);
}
