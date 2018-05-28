/**
 * The basic attribute component. Attributes are the core building blocks of a character entity.
 * Attributes don't intrinsically have a "base" value. The base is given from the flat modifier that
 * corresponds to the attribute. Naturally, this means they default to 0.
 */
#pragma once

#include "entityx/entityx.h"

struct Attribute : entityx::Component<Attribute> {
  double current = 0
  double maximum = 0;
};
