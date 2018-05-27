/**
 * tests/modifiers/increased_vs_more.cpp
 * Tests standard positive scaling modifier interactions with components.
 * "increased" modifiers are an additive scale while "more" modifiers are multiplicative.
 */
#include <vector>

#include "catch.hpp"
#include "components/Life.hpp"
#include "components/Mana.hpp"
#include "components/modifiers/IncreasedLife.hpp"
#include "entityx/entityx.h"
#include "systems/ScalingModifierSystem.hpp"

namespace ex = entityx;

TEST_CASE("increased life scales appropriately", "[modifiers][character]") {
  ex::EventManager events;
  ex::EntityManager entities(events);
  ex::SystemManager systems(entities, events);

  ex::Entity e = entities.create();

  systems.add<ScalingModifierSystem>();
  systems.configure();

  e.assign<Life>(100);
  CHECK(100 == e.component<Life>()->total);

  e.assign<Mana>(100);
  CHECK(100 == e.component<Mana>()->total);

  e.assign<IncreasedLife>(10);
  CHECK(10 == e.component<IncreasedLife>()->total);

  systems.update<ScalingModifierSystem>(0.0);
  CHECK(110 == e.component<Life>()->total);
  CHECK(100 == e.component<Mana>()->total);
}
