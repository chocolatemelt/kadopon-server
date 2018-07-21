/**
 * A list of modifiers attached to an entity. ModifierLists can be applied and removed
 * from themselves.
 */
#pragma once

#include <vector>

#include "modifiers/Modifier.hpp"

struct ModifierList : entityx::Component<ModifierList> {
  std::vector<Modifier *> list;
};
