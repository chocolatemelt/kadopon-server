/**
 * Additive modifier parent class. This covers "increased" and "reduced" modifiers.
 */
#pragma once

#include "entityx/entityx.h"

struct ScalingComponent : entityx::Component<ScalingComponent> {
  int value = 0;
};
