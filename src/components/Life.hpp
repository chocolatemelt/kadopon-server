#ifndef COMPONENT_LIFE_HPP
#define COMPONENT_LIFE_HPP

#include "entityx/entityx.h"

struct Life : entityx::Component<Life> {
  Life(int l = 0) : life(l) {}

  int life;
};

#endif
