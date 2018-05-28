/**
 * Additive modifier parent class. This covers "increased" and "reduced" modifiers.
 */
#pragma once

#include "components/modifiers/Modifier.hpp"

struct AdditiveModifier : Modifier {
  int value = 0;

  AdditiveModifier(int v) : value(v) {}
};
