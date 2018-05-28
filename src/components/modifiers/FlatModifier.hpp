/**
 * Flat modifier parent class. This refers specifically to flat increases to the base.
 */
#pragma once

#include "entityx/entityx.h"

struct FlatModifier : entityx::Component<FlatModifier> {
  int value = 0;
};
