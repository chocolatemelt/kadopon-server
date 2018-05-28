/**
 * Additive modifier parent class. This covers "increased" and "reduced" modifiers.
 */
#pragma once

#include "components/modifiers/Modifier.hpp"

struct AdditiveModifier : Modifier {
  AdditiveModifier(int v) : Modifier(v) {}
};
