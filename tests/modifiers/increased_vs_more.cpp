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

// EntityX ??? class
class EntitiesFixture : public ex::EntityX {
 public:
  std::vector<ex::Entity> created_entities;

  EntitiesFixture() {
		ex::Entity e;
		created_entities.push_back(e);
		Character c1("ranger", e);
		e.assign<Life>(100);
  }
};

TEST_CASE_METHOD(EntitiesFixture, "increased life scales appropriately", "[modifiers][character]") {
	systems.add<ScalingModifierSystem>();
	systems.configure();

  systems.update<ScalingModifierSystem>(0);
	ex::ComponentHandle<Life> life;
	for(auto e : created_entities) {
		e.unpack<Life>(life);
		CHECK(110 == life->life);
	}
}
