#pragma once

#include <unordered_map>

#include "entityx/entityx.h"

struct ScalingComponent : entityx::Component<ScalingComponent> {
  // in short: total = (base + flat) * additive * product sum(multiplicative)
  double base;
  double total;
  int flat = 0;
  int additive = 0;
  std::unordered_map<int, int> multipliers;

  ScalingComponent(double s = 0.0) : base(s), total(s) {}
};
