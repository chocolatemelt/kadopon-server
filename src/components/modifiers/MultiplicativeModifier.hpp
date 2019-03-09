/**
 * Multiplicative modifier parent class. This corresponds to "more" and "less" modifiers.
 */
#pragma once

#include <unordered_map>

#include "components/modifiers/Modifier.hpp"

struct MultiplicativeModifier : Modifier {
  MultiplicativeModifier() : Modifier() {}

  MultiplicativeModifier(int v) : Modifier() {
    if(v > 0) ++more[v];
    else if(v < 0) ++less[v];
  }
};