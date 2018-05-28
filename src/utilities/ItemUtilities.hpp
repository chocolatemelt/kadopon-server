/**
 * Various utility functions for managing items.
 */
#pragma once

#include <cmath>
#include <tuple>
#include <type_traits>

#include "components/attributes/Attribute.hpp"
#include "components/modifiers/AdditiveModifier.hpp"
#include "components/modifiers/FlatModifier.hpp"
#include "components/modifiers/MultiplicativeModifier.hpp"
#include "entityx/entityx.h"
#include "utilities/ModifierUtilities.hpp"

class ItemUtilities {
public:
  static void equip_item(entityx::Entity character, entityx::Entity item) {
    
  }

private:
  ItemUtilities() {}
};
