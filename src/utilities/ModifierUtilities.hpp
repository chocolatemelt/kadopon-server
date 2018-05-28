/**
 * utilities/ModifierUtilities.hpp
 * Various utility functions for managing modifiers.
 */
#pragma once

#include <cmath>
// #include <string>
// #include <type_traits>

#include "entityx/entityx.h"

class ModifierUtilities {
public:
  template <typename Base, typename Add, typename Flat, typename Multi>
  static void update_total(entityx::ComponentHandle<Base> base,
                       		 entityx::ComponentHandle<Add> add,
                     	     entityx::ComponentHandle<Flat> flat,
                           entityx::ComponentHandle<Multi> multi) {
    base->maximum = flat->value * (1 + (add->value / 100.0));
    // apply more multipliers separately, based on their count
    for(auto multi : multi->multipliers) {
      base->maximum *= std::pow((1 + (multi.first / 100.0)), multi.second);
    }
  }

private:
  ModifierUtilities() {}
};
