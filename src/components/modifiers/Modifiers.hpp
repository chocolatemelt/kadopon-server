/**
 * Collection of all core modifiers.
 */
#pragma once

#include "components/modifiers/FlatModifier.hpp"
#include "components/modifiers/AdditiveModifier.hpp"
#include "components/modifiers/MultiplicativeModifier.hpp"
#include "misc/Constants.hpp"

/**
 * Life modifiers
 */
struct FlatLife : FlatModifier {
  FlatLife() : FlatModifier() { id_ = constants::FLAT_LIFE; }
  FlatLife(int v) : FlatModifier(v) { id_ = constants::FLAT_LIFE; }
};

struct AdditiveLife : AdditiveModifier {
  AdditiveLife() : AdditiveModifier() { id_ = constants::ADD_LIFE; }
  AdditiveLife(int v) : AdditiveModifier(v) { id_ = constants::ADD_LIFE; }
};

struct MultiplicativeLife : MultiplicativeModifier {
  MultiplicativeLife() : MultiplicativeModifier() { id_ = constants::MULTI_LIFE; }
  MultiplicativeLife(int v) : MultiplicativeModifier(v) { id_ = constants::MULTI_LIFE; }
};

/**
 * Mana modifiers
 */
 struct FlatMana : FlatModifier {
   FlatMana() : FlatModifier() { id_ = constants::FLAT_MANA; }
   FlatMana(int v) : FlatModifier(v) { id_ = constants::FLAT_MANA; }
 };

 struct AdditiveMana : AdditiveModifier {
   AdditiveMana() : AdditiveModifier() { id_ = constants::ADD_MANA; }
   AdditiveMana(int v) : AdditiveModifier(v) { id_ = constants::ADD_MANA; }
 };

 struct MultiplicativeMana : MultiplicativeModifier {
   MultiplicativeMana() : MultiplicativeModifier() { id_ = constants::MULTI_MANA; }
   MultiplicativeMana(int v) : MultiplicativeModifier(v) { id_ = constants::MULTI_MANA; }
 };

  /**
  * Life regen modifiers
  */
  struct FlatLifeRegen : FlatModifier {
    FlatLifeRegen() : FlatModifier() { id_ = constants::FLAT_LIFE_REGEN; }
    FlatLifeRegen(int v) : FlatModifier(v) { id_ = constants::FLAT_LIFE_REGEN; }
  };

  struct AdditiveLifeRegen : AdditiveModifier {
    AdditiveLifeRegen() : AdditiveModifier() { id_ = constants::ADD_LIFE_REGEN; }
    AdditiveLifeRegen(int v) : AdditiveModifier(v) { id_ = constants::ADD_LIFE_REGEN; }
  };

  /**
  * Mana regen modifiers
  */
  struct FlatManaRegen : FlatModifier {
    FlatManaRegen() : FlatModifier() { id_ = constants::FLAT_MANA_REGEN; }
    FlatManaRegen(int v) : FlatModifier(v) { id_ = constants::FLAT_MANA_REGEN; }
  };

  struct AdditiveManaRegen : AdditiveModifier {
    AdditiveManaRegen() : AdditiveModifier() { id_ = constants::ADD_MANA_REGEN; }
    AdditiveManaRegen(int v) : AdditiveModifier(v) { id_ = constants::ADD_MANA_REGEN; }
  };

 /**
  * Armour modifiers
  */
  struct FlatArmour : FlatModifier {
    FlatArmour() : FlatModifier() { id_ = constants::FLAT_ARMOUR; }
    FlatArmour(int v) : FlatModifier(v) { id_ = constants::FLAT_ARMOUR; }
  };

  struct AdditiveArmour : AdditiveModifier {
    AdditiveArmour() : AdditiveModifier() { id_ = constants::ADD_ARMOUR; }
    AdditiveArmour(int v) : AdditiveModifier(v) { id_ = constants::ADD_ARMOUR; }
  };

  struct MultiplicativeArmour : MultiplicativeModifier {
    MultiplicativeArmour() : MultiplicativeModifier() { id_ = constants::MULTI_ARMOUR; }
    MultiplicativeArmour(int v) : MultiplicativeModifier(v) { id_ = constants::MULTI_ARMOUR; }
  };

  /**
  * Evasion modifiers
  */
  struct FlatEvasion : FlatModifier {
    FlatEvasion() : FlatModifier() { id_ = constants::FLAT_EVASION; }
    FlatEvasion(int v) : FlatModifier(v) { id_ = constants::FLAT_EVASION; }
  };

  struct AdditiveEvasion : AdditiveModifier {
    AdditiveEvasion() : AdditiveModifier() { id_ = constants::ADD_EVASION; }
    AdditiveEvasion(int v) : AdditiveModifier(v) { id_ = constants::ADD_EVASION; }
  };

  struct MultiplicativeEvasion : MultiplicativeModifier {
    MultiplicativeEvasion() : MultiplicativeModifier() { id_ = constants::MULTI_EVASION; }
    MultiplicativeEvasion(int v) : MultiplicativeModifier(v) { id_ = constants::MULTI_EVASION; }
  };

  /**
  * Accuracy modifiers
  */
  struct FlatAccuracy : FlatModifier {
    FlatAccuracy() : FlatModifier() { id_ = constants::FLAT_ACCURACY; }
    FlatAccuracy(int v) : FlatModifier(v) { id_ = constants::FLAT_ACCURACY; }
  };

  struct AdditiveAccuracy : AdditiveModifier {
    AdditiveAccuracy() : AdditiveModifier() { id_ = constants::ADD_ACCURACY; }
    AdditiveAccuracy(int v) : AdditiveModifier(v) { id_ = constants::ADD_ACCURACY; }
  };

  /**
  * Block modifiers
  */
  struct FlatBlock : FlatModifier {
    FlatBlock() : FlatModifier() { id_ = constants::FLAT_BLOCK; }
    FlatBlock(int v) : FlatModifier(v) { id_ = constants::FLAT_BLOCK; }
  };

  struct AdditiveBlock : AdditiveModifier {
    AdditiveBlock() : AdditiveModifier() { id_ = constants::ADD_BLOCK; }
    AdditiveBlock(int v) : AdditiveModifier(v) { id_ = constants::ADD_BLOCK; }
  };

  /**
  * Dodge modifiers
  */
  struct FlatDodge : FlatModifier {
    FlatDodge() : FlatModifier() { id_ = constants::FLAT_DODGE; }
    FlatDodge(int v) : FlatModifier(v) { id_ = constants::FLAT_DODGE; }
  };

  struct AdditiveDodge : AdditiveModifier {
    AdditiveDodge() : AdditiveModifier() { id_ = constants::ADD_DODGE; }
    AdditiveDodge(int v) : AdditiveModifier(v) { id_ = constants::ADD_DODGE; }
  };

  /**
  * Elemental resistance modifiers
  */
  struct FlatFireRes : FlatModifier {
    FlatFireRes() : FlatModifier() { id_ = constants::FLAT_FIRE_RES; }
    FlatFireRes(int v) : FlatModifier(v) { id_ = constants::FLAT_FIRE_RES; }
  };

  struct FlatColdRes : FlatModifier {
    FlatColdRes() : FlatModifier() { id_ = constants::FLAT_COLD_RES; }
    FlatColdRes(int v) : FlatModifier(v) { id_ = constants::FLAT_COLD_RES; }
  };

  struct FlatLightningRes : FlatModifier {
    FlatLightningRes() : FlatModifier() { id_ = constants::FLAT_LIGHTNING_RES; }
    FlatLightningRes(int v) : FlatModifier(v) { id_ = constants::FLAT_LIGHTNING_RES; }
  };

  /**
  * Critical chance modifiers
  */
  struct AdditiveCritChance : AdditiveModifier {
    AdditiveCritChance() : AdditiveModifier() { id_ = constants::ADD_CRIT_CHANCE; }
    AdditiveCritChance(int v) : AdditiveModifier(v) { id_ = constants::ADD_CRIT_CHANCE; }
  };

  /**
  * Critical multiplier modifiers
  */
  struct AdditiveCritMulti : AdditiveModifier {
    AdditiveCritMulti() : AdditiveModifier() { id_ = constants::ADD_CRIT_MULTI; }
    AdditiveCritMulti(int v) : AdditiveModifier(v) { id_ = constants::ADD_CRIT_MULTI; }
  };