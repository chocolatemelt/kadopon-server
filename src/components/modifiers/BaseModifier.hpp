/**
 * Base modifier parent class. This covers flat modifiers.
 */
#pragma once

#include "entityx/entityx.h"

struct ScalingComponent : entityx::Component<ScalingComponent> {
  int value = 0;
};
