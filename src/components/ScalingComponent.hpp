#pragma once

#include "entityx/entityx.h"

struct ScalingComponent : entityx::Component<ScalingComponent> {
  // in short: total = (base + flat) * additive * multiplicative
  double base;
  double total;
  int flat = 0;
  int additive = 0;
  int multiplicative = 0;

  ScalingComponent(double s = 0.0) : base(s), total(s) {}
};
