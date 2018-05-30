/**
 * Item wrapper class over an entity. Items have a variable number of modifier components that
 * get applied selectively to a character when equipped.
 */
#pragma once

#include <utility>
#include <vector>

#include "components/modifiers/FlatModifier.hpp"

class Item {
public:
  std::vector<Modifier *> modifiers;
  entityx::Entity ref;

  Item(entityx::Entity e) : ref(e) {}

  /**
   * Assign a modifier to the wrapped entity and push the modifier handle to modifiers vector.
   * Forwards the arguments for the modifier to entity.assign().
   */
  template <typename M, typename ... Args>
  void add_modifier(Args && ... args) {
    Modifier *handle = ref.assign<M>(std::forward<Args>(args) ...).get();
    modifiers.push_back(handle);
  }
};
