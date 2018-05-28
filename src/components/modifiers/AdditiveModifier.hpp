/**
 * Additive modifier parent class. This covers "increased" and "reduced" modifiers.
 */
#pragma once

#include "entityx/entityx.h"

struct AdditiveModifier : entityx::Component<AdditiveModifier> {
  int value = 0;
};
