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

  // give entity life attribute
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
  ModifierUtilities::modifier_add_multiplier<MultiplicativeLife>(e.component<MultiplicativeLife>(), 10);
  ModifierUtilities::modifier_add_multiplier<MultiplicativeLife>(e.component<MultiplicativeLife>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(206 == static_cast<int>(e.component<Life>()->maximum));

  // give entity mana attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Mana>();
  e.assign<AdditiveMana>(0);
  e.assign<FlatMana>(50);
  e.assign<MultiplicativeMana>();
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(50 == static_cast<int>(e.component<Mana>()->maximum));

  // add 10% increased maximum mana modifier
  ModifierUtilities::modifier_add_value<AdditiveMana>(e.component<AdditiveMana>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(55 == static_cast<int>(e.component<Mana>()->maximum));

  // add +25 to maximum mana modifier
  ModifierUtilities::modifier_add_value<FlatMana>(e.component<FlatMana>(), 25);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(82 == static_cast<int>(e.component<Mana>()->maximum));

  // add two 10% more mana modifiers
  ModifierUtilities::modifier_add_multiplier<MultiplicativeMana>(e.component<MultiplicativeMana>(), 10);
  ModifierUtilities::modifier_add_multiplier<MultiplicativeMana>(e.component<MultiplicativeMana>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(99 == static_cast<int>(e.component<Mana>()->maximum));
/*
  // give entity life regen attribute
  // naturally, we need to assign the appropriate stats
  e.assign<LifeRegen>();
  e.assign<AdditiveLifeRegen>(0);
  e.assign<FlatLifeRegen>(13.3);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(13 == static_cast<int>(e.component<LifeRegen>()->maximum));

  // add 10% increased maximum life regen modifier
  ModifierUtilities::modifier_add_value<AdditiveLifeRegen>(e.component<AdditiveLifeRegen>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(14 == static_cast<int>(e.component<LifeRegen>()->maximum));

  // add +4.5 to maximum life regen modifier
  ModifierUtilities::modifier_add_value<FlatLifeRegen>(e.component<FlatLifeRegen>(), 4.5);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(19 == static_cast<int>(e.component<LifeRegen>()->maximum));

  // give entity mana regen attribute
  // naturally, we need to assign the appropriate stats
  e.assign<ManaRegen>();
  e.assign<AdditiveManaRegen>(0);
  e.assign<FlatManaRegen>(15.6);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(15 == static_cast<int>(e.component<ManaRegen>()->maximum));

  // add 10% increased maximum mana regen modifier
  ModifierUtilities::modifier_add_value<AdditiveManaRegen>(e.component<AdditiveManaRegen>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(17 == static_cast<int>(e.component<ManaRegen>()->maximum));

  // add +2.2 to maximum mana regen modifier
  ModifierUtilities::modifier_add_value<FlatManaRegen>(e.component<FlatManaRegen>(), 2.2);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(19 == static_cast<int>(e.component<ManaRegen>()->maximum));
*/
  // give entity armour attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Armour>();
  e.assign<AdditiveArmour>(0);
  e.assign<FlatArmour>(33);
  e.assign<MultiplicativeArmour>();
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(33 == static_cast<int>(e.component<Armour>()->maximum));

  // add 15% increased maximum armour modifier
  ModifierUtilities::modifier_add_value<AdditiveArmour>(e.component<AdditiveArmour>(), 15);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(37 == static_cast<int>(e.component<Armour>()->maximum));

  // add +40 to maximum armour modifier
  ModifierUtilities::modifier_add_value<FlatArmour>(e.component<FlatArmour>(), 40);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(83 == static_cast<int>(e.component<Armour>()->maximum));

  // add two 10% more armour modifiers
  ModifierUtilities::modifier_add_multiplier<MultiplicativeArmour>(e.component<MultiplicativeArmour>(), 10);
  ModifierUtilities::modifier_add_multiplier<MultiplicativeArmour>(e.component<MultiplicativeArmour>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(101 == static_cast<int>(e.component<Armour>()->maximum));

  // give entity evasion attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Evasion>();
  e.assign<AdditiveEvasion>(0);
  e.assign<FlatEvasion>(67);
  e.assign<MultiplicativeEvasion>();
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(67 == static_cast<int>(e.component<Evasion>()->maximum));

  // add 5% increased maximum evasion modifier
  ModifierUtilities::modifier_add_value<AdditiveEvasion>(e.component<AdditiveEvasion>(), 5);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(70 == static_cast<int>(e.component<Evasion>()->maximum));

  // add +19 to maximum evasion modifier
  ModifierUtilities::modifier_add_value<FlatEvasion>(e.component<FlatEvasion>(), 19);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(90 == static_cast<int>(e.component<Evasion>()->maximum));

  // add two 10% more evasion modifiers
  ModifierUtilities::modifier_add_multiplier<MultiplicativeEvasion>(e.component<MultiplicativeEvasion>(), 10);
  ModifierUtilities::modifier_add_multiplier<MultiplicativeEvasion>(e.component<MultiplicativeEvasion>(), 10);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(109 == static_cast<int>(e.component<Evasion>()->maximum));
/*
  // give entity accuracy attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Accuracy>();
  e.assign<AdditiveAccuracy>(0);
  e.assign<FlatAccuracy>(120);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(120 == static_cast<int>(e.component<Accuracy>()->maximum));

  // add 35% increased maximum accuracy modifier
  ModifierUtilities::modifier_add_value<AdditiveAccuracy>(e.component<AdditiveAccuracy>(), 35);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(162 == static_cast<int>(e.component<Accuracy>()->maximum));

  // add +66 to maximum accuracy modifier
  ModifierUtilities::modifier_add_value<FlatAccuracy>(e.component<FlatAccuracy>(), 66);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(250 == static_cast<int>(e.component<Accuracy>()->maximum));

  // give entity block attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Block>();
  e.assign<FlatBlock>(300);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(300 == static_cast<int>(e.component<Block>()->maximum));

  // add +57 to maximum block modifier
  ModifierUtilities::modifier_add_value<FlatBlock>(e.component<FlatBlock>(), 57);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(357 == static_cast<int>(e.component<Block>()->maximum));

  // give entity dodge attribute
  // naturally, we need to assign the appropriate stats
  e.assign<Dodge>();
  e.assign<FlatDodge>(71);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(71 == static_cast<int>(e.component<Dodge>()->maximum));

  // add +6 to maximum dodge modifier
  ModifierUtilities::modifier_add_value<FlatDodge>(e.component<FlatDodge>(), 6);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(77 == static_cast<int>(e.component<Dodge>()->maximum));

  // give entity fire resistance attribute
  // naturally, we need to assign the appropriate stats
  e.assign<FireRes>();
  e.assign<FlatFireRes>(152);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(152 == static_cast<int>(e.component<FireRes>()->maximum));

  // add +279 to maximum fire resistance modifier
  ModifierUtilities::modifier_add_value<FlatFireRes>(e.component<FlatFireRes>(), 279);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(431 == static_cast<int>(e.component<FireRes>()->maximum));

  // give entity cold resistance attribute
  // naturally, we need to assign the appropriate stats
  e.assign<ColdRes>();
  e.assign<FlatColdRes>(194);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(194 == static_cast<int>(e.component<ColdRes>()->maximum));

  // add +260 to maximum cold resistance modifier
  ModifierUtilities::modifier_add_value<FlatColdRes>(e.component<FlatColdRes>(), 260);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(454 == static_cast<int>(e.component<ColdRes>()->maximum));

  // give entity lightning resistance attribute
  // naturally, we need to assign the appropriate stats
  e.assign<LightningRes>();
  e.assign<FlatLightningRes>(124);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(124 == static_cast<int>(e.component<LightningRes>()->maximum));

  // add +162 to maximum lightning resistance modifier
  ModifierUtilities::modifier_add_value<FlatLightningRes>(e.component<FlatLightningRes>(), 162);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(286 == static_cast<int>(e.component<LightningRes>()->maximum));

  // give entity critical chance attribute
  // naturally, we need to assign the appropriate stats
  e.assign<CritChance>();
  e.assign<FlatCritChance>(67);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(67 == static_cast<int>(e.component<CritChance>()->maximum));

  // add +190 to maximum critical chance modifier
  ModifierUtilities::modifier_add_value<FlatCritChance>(e.component<FlatCritChance>(), 190);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(257 == static_cast<int>(e.component<CritChance>()->maximum));

  // give entity critical multiplier attribute
  // naturally, we need to assign the appropriate stats
  e.assign<CritMulti>();
  e.assign<FlatCritMulti>(65);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(65 == static_cast<int>(e.component<CritMulti>()->maximum));

  // add +8 to maximum critical multiplier modifier
  ModifierUtilities::modifier_add_value<FlatCritMulti>(e.component<FlatCritMulti>(), 8);
  systems.update<ScalingModifierSystem>(0.0);
  CHECK(73 == static_cast<int>(e.component<CritMulti>()->maximum));*/
}
