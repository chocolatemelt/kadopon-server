/**
 * Tests standard positive scaling modifier interactions with components.
 * "increased" modifiers are an additive scale while "more" modifiers are multiplicative.
 */
#include <vector>

#include "catch.hpp"
#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entityx/entityx.h"
#include "systems/ScalingModifierSystem.hpp"
#include "utilities/ModifierUtilities.hpp"

namespace ex = entityx;

TEST_CASE("increased life scales appropriately", "[modifiers][character]") {
  // basic game system setup
  ex::EventManager events;
  ex::EntityManager entities(events);
  ex::SystemManager systems(entities, events);

  // add the modifier system
  systems.add<ScalingModifierSystem>();
  systems.configure();
  
  // create an example entity
  ex::Entity e = entities.create();

  // give entity Life attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Life>();
  e.assign<AdditiveLife>(0);
  e.assign<FlatLife>(100);
  e.assign<MultiplicativeLife>();
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(100 == static_cast<int>(e.component<Life>()->maximum));

  // add 10% increased maximum life modifier
  ModifierUtilities::modifier_add_value<AdditiveLife>(e.component<AdditiveLife>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(110 == static_cast<int>(e.component<Life>()->maximum));

  // add +55 to maximum life modifier
  ModifierUtilities::modifier_add_value<FlatLife>(e.component<FlatLife>(), 55);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(170 == static_cast<int>(e.component<Life>()->maximum));

  // add two 10% more life modifiers
  ModifierUtilities::modifier_add_multiplier(e.component<MultiplicativeLife>(), 10);
  ModifierUtilities::modifier_add_multiplier(e.component<MultiplicativeLife>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(206 == static_cast<int>(e.component<Life>()->maximum));
}
