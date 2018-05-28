/**
 * utilities/ModifierUtilities.hpp
 * Various utility functions for managing modifiers.
 */
#pragma once

#include <cmath>
// #include <string>
#include <type_traits>

#include "components/modifiers/AdditiveModifier.hpp"
#include "components/modifiers/FlatModifier.hpp"
#include "components/modifiers/MultiplicativeModifier.hpp"
#include "entityx/entityx.h"

class ModifierUtilities {
public:
  /**
   * Adds value to a flat or additive multiplier.
   * @param mod   modifier to be updated
   * @param value value to add to the modifier
   */
  template <typename Modifier>
  static void modifier_add_value(entityx::ComponentHandle<Modifier> mod, int value) {
    if(std::is_base_of<AdditiveModifier, Modifier>::value || std::is_base_of<FlatModifier, Modifier>::value) {
      mod->value += value;
    }
  }

  /**
   * For multiplicative modifiers, a negative value is construed as a "less" modifier, while
   * positive values are considered "more" modifiers.
   * @param mod   modifier to be updated
   * @param value value to add to the modifier
   */
  template <typename Modifier>
  static void modifier_add_multiplier(entityx::ComponentHandle<Modifier> mod, int value) {
    if(std::is_base_of<MultiplicativeModifier, Modifier>::value) {
      // multiplicative modifiers are held in a map with their count; simply increment if it exists
      // if the value is negative, we add it to the "less" map instead
      if(value > 0) {
      	if(mod->more.find(value) != mod->more.end()) ++mod->more[value];
      	else mod->more[value] = 1;
      }
      else {
        if(mod->less.find(value) != mod->less.end()) ++mod->less[value];
      	else mod->less[value] = 1;
      }
    }
  }

  /**
   * Updates the base attribute using the corresponding modifiers.
   * @param base  base attribute
   * @param add   additive modifier
   * @param flat  flat modifier
   * @param multi multiplicative modifer
   */
  template <typename Base, typename Add, typename Flat, typename Multi>
  static void update_total(entityx::ComponentHandle<Base> base,
                       		 entityx::ComponentHandle<Add> add,
                     	     entityx::ComponentHandle<Flat> flat,
                           entityx::ComponentHandle<Multi> multi) {
    base->maximum = flat->value * (1 + (add->value / 100.0));
    // apply more multipliers separately, based on their count
    for(auto multi : multi->more) {
      base->maximum *= std::pow((1 + (multi.first / 100.0)), multi.second);
    }
    for(auto multi : multi->less) {
      base->maximum /= std::pow((1 + (multi.first / 100.0)), multi.second);
    }
  }

private:
  ModifierUtilities() {}
};
