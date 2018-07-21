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
