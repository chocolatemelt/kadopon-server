/**
 * Item wrapper class over an entity. Items have a variable number of modifier components that
 * get applied selectively to a character when equipped.
 */
#pragma once

#include <vector>

#include "components/modifiers/FlatModifier.hpp"

class Item {
public:
  std::vector<Modifier *> modifiers;
  entityx::Entity ref;

  Item(entityx::Entity e) : ref(e) {}

  void add_modifier(Modifier *);
};
