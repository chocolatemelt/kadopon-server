/**
 * components/Life.hpp
 * Basic Life component. This should be displayed as an integer, but the internal representation
 * is a double.
 */
#pragma once

#include "entityx/entityx.h"

struct Life : entityx::Component<Life> {
  Life(double l = 0.0) : current(l), base(l), total(l) {}

  double current, base, total;
};
