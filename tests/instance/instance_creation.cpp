/**
 * Tests creation of game instance and validity of entityx components.
 */

#include "catch.hpp"
#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entities/Character.hpp"
#include "entityx/entityx.h"
#include "instance/GameInstance.hpp"

TEST_CASE("creates a game instance", "[instance]") {
  GameInstance instance;

  Character ranger(instance.entities.create());
  instance.entities.each<AdditiveLife>([](entityx::Entity entity, AdditiveLife &mana) {
    CHECK(0 == mana.value);
  });
  instance.entities.each<Life>([](entityx::Entity entity, Life &life) {
    CHECK(0 == life.current);
  });
}
