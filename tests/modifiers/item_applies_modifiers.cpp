/**
 * Tests item interactions with modifiers of a given entity.
 */
#include <vector>

#include "catch.hpp"
#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entities/Item.hpp"
#include "entityx/entityx.h"
#include "systems/ScalingModifierSystem.hpp"
#include "utilities/ItemUtilities.hpp"
#include "utilities/ModifierUtilities.hpp"

namespace ex = entityx;

TEST_CASE("equipping item scales life appropriately", "[modifiers][character][item]") {
  // basic game system setup
  ex::EventManager events;
  ex::EntityManager entities(events);
  ex::SystemManager systems(entities, events);

  // add the modifier system
  systems.add<ScalingModifierSystem>();
  systems.configure();

  // create a character
  ex::Entity ranger = entities.create();

  // give entity Life attribute
  // naturally, we need to assign the appropriate stats
  ranger.assign<Life>();
  ranger.assign<AdditiveLife>(0);
  ranger.assign<FlatLife>(100);
  ranger.assign<MultiplicativeLife>();
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(100 == static_cast<int>(ranger.component<Life>()->maximum));

  // create an item:
  // +55 to maximum life
  // 7% more maximum life
  // this likely would never show up as an actual item, but it tests flat vs multiplicative mods
  Item chest(entities.create());
  chest.add_modifier<FlatLife>(55);
  chest.add_modifier<MultiplicativeLife>(7);
  CHECK(55 == static_cast<int>(chest.ref.component<FlatLife>()->value));
  CHECK(1 == chest.ref.component<MultiplicativeLife>()->more.find(7)->second);

  // equip the chest
  ItemUtilities::equip_item(ranger, chest);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(165 == static_cast<int>(ranger.component<Life>()->maximum));
}
