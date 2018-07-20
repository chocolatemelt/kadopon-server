/**
 * Collection of all core modifiers, i.e. modifiers directly used by the game.
 */
#pragma once

#include "components/modifiers/FlatModifier.hpp"
#include "components/modifiers/AdditiveModifier.hpp"
#include "components/modifiers/MultiplicativeModifier.hpp"

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
