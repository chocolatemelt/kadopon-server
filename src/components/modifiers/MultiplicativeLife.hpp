#pragma once

#include "components/modifiers/MultiplicativeModifier.hpp"

struct MultiplicativeLife : MultiplicativeModifier {
  MultiplicativeLife() : MultiplicativeModifier() {}
  MultiplicativeLife(int v) : MultiplicativeModifier(v) {}
};
