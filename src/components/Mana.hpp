/**
 * components/Mana.hpp
 * Basic Mana component. This should be displayed as an integer, but the internal representation
 * is a double.
 */
#pragma once

#include "components/ScalingComponent.hpp"
#include "entityx/entityx.h"

struct Mana : ScalingComponent {
  double current;

  Mana(double m = 0.0) : ScalingComponent(m), current(m) {}
};
