#include "entities/Item.hpp"

void Item::add_modifier(Modifier *mod) {
  modifiers.push_back(mod);
}
