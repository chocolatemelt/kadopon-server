/**
 * Flat modifier parent class. This refers specifically to flat increases to the base.
 */
#pragma once

#include "components/modifiers/Modifier.hpp"

struct FlatModifier : Modifier {
  int value = 0;

  FlatModifier(int v) : value(v) {}
};
