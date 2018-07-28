/**
 * Flat modifier parent class. This refers specifically to flat increases to the base.
 */
#pragma once

#include "components/modifiers/Modifier.hpp"

struct FlatModifier : Modifier {
  FlatModifier() : Modifier() {}
  FlatModifier(int v) : Modifier(v) {}
};
