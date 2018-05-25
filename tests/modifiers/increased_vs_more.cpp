/**
 * tests/modifiers/increased_vs_more.cpp
 * Tests standard positive scaling modifier interactions with components.
 * "increased" modifiers are an additive scale while "more" modifiers are multiplicative.
 */
#include <vector>

#include "catch.hpp"
#include "components/Life.hpp"
#include "entities/Character.hpp"
#include "entityx/entityx.h"
#include "systems/ScalingModifierSystem.hpp"

namespace ex = entityx;

TEST_CASE("increased life scales appropriately", "[modifiers][character]") {
  ex::Entity e;
  ex::EventManager events;
  ex::EntityManager manager(events);
  e = manager.create();

  Character c1("ranger", e);
  e.assign<Life>(100);
  CHECK(100 == e.component<Life>()->life);
}
