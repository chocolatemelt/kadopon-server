/**
 * components/life.hpp
 * Basic Life component. This should be displayed as an integer, but the internal representation
 * is a double.
 */
#ifndef COMPONENT_LIFE_HPP
#define COMPONENT_LIFE_HPP

#include "entityx/entityx.h"

struct Life : entityx::Component<Life> {
  Life(double l = 0.0) : life(l) {}

  double life;
};

#endif
