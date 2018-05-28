/**
 * tests/modifiers/increased_vs_more.cpp
 * Tests standard positive scaling modifier interactions with components.
 * "increased" modifiers are an additive scale while "more" modifiers are multiplicative.
 */
#include <vector>

#include "catch.hpp"
#include "components/Components.hpp"
#include "entityx/entityx.h"
#include "systems/ScalingModifierSystem.hpp"
#include "utilities/ModifierUtilities.hpp"

namespace ex = entityx;

TEST_CASE("increased life scales appropriately", "[modifiers][character]") {
  // basic game system setup
  ex::EventManager events;
  ex::EntityManager entities(events);
  ex::SystemManager systems(entities, events);

  // create an example entity
  ex::Entity e = entities.create();

  // add the modifier system
  systems.add<ScalingModifierSystem>();
  systems.configure();

  // assign Life and Mana components to the entity
  e.assign<Life>(100);
  CHECK(100 == e.component<Life>()->total);

  e.assign<Mana>(100);
  CHECK(100 == e.component<Mana>()->total);

  // add 10% increased maximum life modifier
  ModifierUtilities::add_additive_mod(e.component<Life>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(110 == static_cast<int>(e.component<Life>()->total));

  // add +55 to maximum life modifier
  ModifierUtilities::add_flat_mod(e.component<Life>(), 55);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(170 == static_cast<int>(e.component<Life>()->total));

  // add two 10% more life modifiers
  ModifierUtilities::add_multiplicative_mod(e.component<Life>(), 10);
  ModifierUtilities::add_multiplicative_mod(e.component<Life>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(206 == static_cast<int>(e.component<Life>()->total));
}
