/**
 * components/Life.hpp
 * Basic Life component. This should be displayed as an integer, but the internal representation
 * is a double.
 */
#pragma once

#include "components/ScalingComponent.hpp"
#include "entityx/entityx.h"

struct Life : ScalingComponent {
  Life(double l = 0.0) : ScalingComponent(l), current(l) {}

  double current;
};
