/**
 * Multiplicative modifier parent class. This corresponds to "more" and "less" modifiers.
 */
#pragma once

#include <unordered_map>

#include "components/modifiers/Modifier.hpp"

struct MultiplicativeModifier : Modifier {
  std::unordered_map<int, int> more;
  std::unordered_map<int, int> less;
};
