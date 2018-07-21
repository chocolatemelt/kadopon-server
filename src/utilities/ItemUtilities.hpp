/**
 * Various utility functions for managing items.
 */
#pragma once

#include "entities/Character.hpp"
#include "entities/Item.hpp"
#include "entityx/entityx.h"

class ItemUtilities {
public:
  static void equip_item(entityx::Entity, Item);
  static void equip_item(Character, Item);

private:
  ItemUtilities() {}
};
