/**
 * components/Mana.hpp
 * Basic Mana component. This should be displayed as an integer, but the internal representation
 * is a double.
 */
#pragma once

#include "entityx/entityx.h"

struct Mana : entityx::Component<Mana> {
  Mana(double l = 0.0) : current(l), base(l), total(l) {}

  double current, base, total;
};
