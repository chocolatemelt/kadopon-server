/**
 * Collection of all core modifiers.
 */
#pragma once

#include "components/modifiers/FlatModifier.hpp"
#include "components/modifiers/AdditiveModifier.hpp"
#include "components/modifiers/MultiplicativeModifier.hpp"

/**
 * Life modifiers
 */
struct FlatLife : FlatModifier {
  FlatLife() : FlatModifier() { id_ = "FLAT_LIFE"; }
  FlatLife(int v) : FlatModifier(v) { id_ = "FLAT_LIFE"; }
};

struct AdditiveLife : AdditiveModifier {
  AdditiveLife() : AdditiveModifier() { id_ = "ADDITIVE_LIFE"; }
  AdditiveLife(int v) : AdditiveModifier(v) { id_ = "ADDITIVE_LIFE"; }
};

struct MultiplicativeLife : MultiplicativeModifier {
  MultiplicativeLife() : MultiplicativeModifier() { id_ = "MULTIPLICATIVE_LIFE"; }
  MultiplicativeLife(int v) : MultiplicativeModifier(v) { id_ = "MULTIPLICATIVE_LIFE"; }
};

/**
 * Mana modifiers
 */
 struct FlatMana : FlatModifier {
   FlatMana() : FlatModifier() { id_ = "FLAT_LIFE"; }
   FlatMana(int v) : FlatModifier(v) { id_ = "FLAT_LIFE"; }
 };

 struct AdditiveMana : AdditiveModifier {
   AdditiveMana() : AdditiveModifier() { id_ = "ADDITIVE_LIFE"; }
   AdditiveMana(int v) : AdditiveModifier(v) { id_ = "ADDITIVE_LIFE"; }
 };

 struct MultiplicativeMana : MultiplicativeModifier {
   MultiplicativeMana() : MultiplicativeModifier() { id_ = "MULTIPLICATIVE_LIFE"; }
   MultiplicativeMana(int v) : MultiplicativeModifier(v) { id_ = "MULTIPLICATIVE_LIFE"; }
 };
