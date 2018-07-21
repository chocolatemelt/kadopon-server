/**
 * Tests creation of game instance and validity of entityx components.
 */

#include "catch.hpp"
#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entities/Character.hpp"
#include "entityx/entityx.h"
#include "instance/GameInstance.hpp"
#include "utilities/ItemUtilities.hpp"

TEST_CASE("creates a game instance", "[instance]") {
  GameInstance instance;
  Character ranger(instance.create());

  instance.entities.each<AdditiveLife>([](entityx::Entity entity, AdditiveLife &mana) {
    CHECK(0 == mana.value);
  });
  instance.entities.each<Life>([](entityx::Entity entity, Life &life) {
    CHECK(0 == life.maximum);
  });
}

TEST_CASE("updates modifiers", "[instance][modifiers][character][item]") {
  GameInstance instance;
  Character ranger(instance.create());
  Item helmet(instance.create());

  helmet.add_modifier<FlatLife>(10);
  helmet.add_modifier<AdditiveLife>(10);
  helmet.add_modifier<MultiplicativeLife>(10);
  ItemUtilities::equip_item(ranger, helmet);
  instance.update_modifiers();
  CHECK(12 == static_cast<int>(ranger.component<Life>()->maximum));
}

TEST_CASE("instance creates relevant component dependencies", "[instance][character]") {
  GameInstance instance;
  Character ranger(instance.create());

  int count = 0;
  instance.entities.each<Life, FlatLife, AdditiveLife, MultiplicativeLife>([&count](
    entityx::Entity entity,
    Life &l,
    FlatLife &fl,
    AdditiveLife &al,
    MultiplicativeLife &ml) {
      ++count;
    });

  CHECK(1 == count);
}
