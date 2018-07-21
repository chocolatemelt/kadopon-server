#include "entities/Item.hpp"

Item::Item(entityx::Entity e) : ref(e) {
  modifiers = ref.assign<ModifierList>().get();
}
