/**
 * Multiplicative modifier parent class. This corresponds to "more" and "less" modifiers.
 */
#pragma once

#include <unordered_map>

#include "components/modifiers/Modifier.hpp"

struct MultiplicativeModifier : Modifier {
  MultiplicativeModifier() : Modifier(0) {}
};
