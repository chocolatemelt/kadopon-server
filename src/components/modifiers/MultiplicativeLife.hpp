#pragma once

#include "components/modifiers/MultiplicativeModifier.hpp"

struct MultiplicativeLife : MultiplicativeModifier {
  MultiplicativeLife() : MultiplicativeModifier() { id_ = "MULTIPLICATIVE_LIFE"; }
  MultiplicativeLife(int v) : MultiplicativeModifier(v) { id_ = "MULTIPLICATIVE_LIFE"; }
};
