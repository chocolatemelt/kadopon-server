/**
 * components/ModifierList.hpp
 * Basic component for the entire list of modifiers attached to an entity.
 */
#pragma once

#include <vector> // probably switch this at a later date; really bad for what i'm planning

#include "components/ModifierList.hpp"
#include "entityx/entityx.h"
#include "modifiers/Modifier.hpp"

struct ModifierList : entityx::Component<ModifierList> {
  std::vector<Modifier> modifiers;
};
