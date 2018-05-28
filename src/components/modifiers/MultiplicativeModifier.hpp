/**
 * Multiplicative modifier parent class. This corresponds to "more" and "less" modifiers.
 */
#pragma once

#include <unordered_map>

#include "entityx/entityx.h"

struct MultiplicativeModifier : entityx::Component<MultiplicativeModifier> {
  std::unordered_map<int, int> more;
  std::unordered_map<int, int> less;
};
