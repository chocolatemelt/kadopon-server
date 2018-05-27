#pragma once

#include "entityx/entityx.h"

struct ScalingComponent : entityx::Component<ScalingComponent> {
  // in short: total = (base + flat) * additive * multiplicative
  double base;
  double total;
  int flat_modifier = 0;
  int additive_modifier = 0;
  int multiplicative_modifier = 0;

  ScalingComponent(double s = 0.0) : base(s), total(s) {}
};
