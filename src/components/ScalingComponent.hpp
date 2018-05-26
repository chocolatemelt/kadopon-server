#pragma once

#include "entityx/entityx.h"

struct ScalingComponent : entityx::Component<ScalingComponent> {
  ScalingComponent(double s = 0.0) : base(s), total(s) {}

  double base, total;
};
