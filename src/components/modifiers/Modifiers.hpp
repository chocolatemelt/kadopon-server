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
  FlatLife() : FlatModifier() { id_ = Constants::FLAT_LIFE; }
  FlatLife(int v) : FlatModifier(v) { id_ = Constants::FLAT_LIFE; }
};

struct AdditiveLife : AdditiveModifier {
  AdditiveLife() : AdditiveModifier() { id_ = Constants::ADD_LIFE; }
  AdditiveLife(int v) : AdditiveModifier(v) { id_ = Constants::ADD_LIFE; }
};

struct MultiplicativeLife : MultiplicativeModifier {
  MultiplicativeLife() : MultiplicativeModifier() { id_ = Constants::MULTI_LIFE; }
  MultiplicativeLife(int v) : MultiplicativeModifier(v) { id_ = Constants::MULTI_LIFE; }
};

/**
 * Mana modifiers
 */
 struct FlatMana : FlatModifier {
   FlatMana() : FlatModifier() { id_ = Constants::FLAT_MANA; }
   FlatMana(int v) : FlatModifier(v) { id_ = Constants::FLAT_MANA; }
 };

 struct AdditiveMana : AdditiveModifier {
   AdditiveMana() : AdditiveModifier() { id_ = Constants::ADD_MANA; }
   AdditiveMana(int v) : AdditiveModifier(v) { id_ = Constants::ADD_MANA; }
 };

 struct MultiplicativeMana : MultiplicativeModifier {
   MultiplicativeMana() : MultiplicativeModifier() { id_ = Constants::MULTI_MANA; }
   MultiplicativeMana(int v) : MultiplicativeModifier(v) { id_ = Constants::MULTI_MANA; }
 };

  /**
  * Life regen modifiers
  */
  struct FlatLifeRegen : FlatModifier {
    FlatLifeRegen() : FlatModifier() { id_ = Constants::FLAT_LIFE_REGEN; }
    FlatLifeRegen(int v) : FlatModifier(v) { id_ = Constants::FLAT_LIFE_REGEN; }
  };

  struct AdditiveLifeRegen : AdditiveModifier {
    AdditiveLifeRegen() : AdditiveModifier() { id_ = Constants::ADD_LIFE_REGEN; }
    AdditiveLifeRegen(int v) : AdditiveModifier(v) { id_ = Constants::ADD_LIFE_REGEN; }
  };

  /**
  * Mana regen modifiers
  */
  struct FlatManaRegen : FlatModifier {
    FlatManaRegen() : FlatModifier() { id_ = Constants::FLAT_MANA_REGEN; }
    FlatManaRegen(int v) : FlatModifier(v) { id_ = Constants::FLAT_MANA_REGEN; }
  };

  struct AdditiveManaRegen : AdditiveModifier {
    AdditiveManaRegen() : AdditiveModifier() { id_ = Constants::ADD_MANA_REGEN; }
    AdditiveManaRegen(int v) : AdditiveModifier(v) { id_ = Constants::ADD_MANA_REGEN; }
  };

 /**
  * Armour modifiers
  */
  struct FlatArmour : FlatModifier {
    FlatArmour() : FlatModifier() { id_ = Constants::FLAT_ARMOUR; }
    FlatArmour(int v) : FlatModifier(v) { id_ = Constants::FLAT_ARMOUR; }
  };

  struct AdditiveArmour : AdditiveModifier {
    AdditiveArmour() : AdditiveModifier() { id_ = Constants::ADD_ARMOUR; }
    AdditiveArmour(int v) : AdditiveModifier(v) { id_ = Constants::ADD_ARMOUR; }
  };

  struct MultiplicativeArmour : MultiplicativeModifier {
    MultiplicativeArmour() : MultiplicativeModifier() { id_ = Constants::MULTI_ARMOUR; }
    MultiplicativeArmour(int v) : MultiplicativeModifier(v) { id_ = Constants::MULTI_ARMOUR; }
  };

  /**
  * Evasion modifiers
  */
  struct FlatEvasion : FlatModifier {
    FlatEvasion() : FlatModifier() { id_ = Constants::FLAT_EVASION; }
    FlatEvasion(int v) : FlatModifier(v) { id_ = Constants::FLAT_EVASION; }
  };

  struct AdditiveEvasion : AdditiveModifier {
    AdditiveEvasion() : AdditiveModifier() { id_ = Constants::ADD_EVASION; }
    AdditiveEvasion(int v) : AdditiveModifier(v) { id_ = Constants::ADD_EVASION; }
  };

  struct MultiplicativeEvasion : MultiplicativeModifier {
    MultiplicativeEvasion() : MultiplicativeModifier() { id_ = Constants::MULTI_EVASION; }
    MultiplicativeEvasion(int v) : MultiplicativeModifier(v) { id_ = Constants::MULTI_EVASION; }
  };

  /**
  * Accuracy modifiers
  */
  struct FlatAccuracy : FlatModifier {
    FlatAccuracy() : FlatModifier() { id_ = Constants::FLAT_ACCURACY; }
    FlatAccuracy(int v) : FlatModifier(v) { id_ = Constants::FLAT_ACCURACY; }
  };

  struct AdditiveAccuracy : AdditiveModifier {
    AdditiveAccuracy() : AdditiveModifier() { id_ = Constants::ADD_ACCURACY; }
    AdditiveAccuracy(int v) : AdditiveModifier(v) { id_ = Constants::ADD_ACCURACY; }
  };

  /**
  * Block modifiers
  */
  struct FlatBlock : FlatModifier {
    FlatBlock() : FlatModifier() { id_ = Constants::FLAT_BLOCK; }
    FlatBlock(int v) : FlatModifier(v) { id_ = Constants::FLAT_BLOCK; }
  };

  /**
  * Dodge modifiers
  */
  struct FlatDodge : FlatModifier {
    FlatDodge() : FlatModifier() { id_ = Constants::FLAT_DODGE; }
    FlatDodge(int v) : FlatModifier(v) { id_ = Constants::FLAT_DODGE; }
  };

  /**
  * Elemental resistance modifiers
  */
  struct FlatFireRes : FlatModifier {
    FlatFireRes() : FlatModifier() { id_ = Constants::FLAT_FIRE_RES; }
    FlatFireRes(int v) : FlatModifier(v) { id_ = Constants::FLAT_FIRE_RES; }
  };

  struct FlatColdRes : FlatModifier {
    FlatColdRes() : FlatModifier() { id_ = Constants::FLAT_COLD_RES; }
    FlatColdRes(int v) : FlatModifier(v) { id_ = Constants::FLAT_COLD_RES; }
  };

  struct FlatLightningRes : FlatModifier {
    FlatLightningRes() : FlatModifier() { id_ = Constants::FLAT_LIGHTNING_RES; }
    FlatLightningRes(int v) : FlatModifier(v) { id_ = Constants::FLAT_LIGHTNING_RES; }
  };

  /**
  * Critical chance modifiers
  */
  struct FlatCritChance : FlatModifier {
    FlatCritChance() : FlatModifier() { id_ = Constants::FLAT_CRIT_CHANCE; }
    FlatCritChance(int v) : FlatModifier(v) { id_ = Constants::FLAT_CRIT_CHANCE; }
  };

  /**
  * Critical multiplier modifiers
  */
  struct FlatCritMulti : FlatModifier {
    FlatCritMulti() : FlatModifier() { id_ = Constants::FLAT_CRIT_MULTI; }
    FlatCritMulti(int v) : FlatModifier(v) { id_ = Constants::FLAT_CRIT_MULTI; }
  };