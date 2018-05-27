/**
 * utilities/ModifierUtilities.hpp
 * Various utility functions for managing modifiers.
 */
#pragma once

#include <string>
#include <type_traits>

#include "components/ScalingComponent.hpp"
#include "entityx/entityx.h"

class ModifierUtilities {
public:
	template <typename M>
	static void add_modifier(std::string uid, entityx::ComponentHandle<M> handle, int val) {
		if(uid == "FLAT_MAX_LIFE") {
			// check that M is a ScalingComponent before attempting to add the modifier
			if(std::is_base_of<ScalingComponent, M>::value) {
				handle->flat += val;
			}
		}
		else if(uid == "INC_MAX_LIFE") {
			if(std::is_base_of<ScalingComponent, M>::value) {
				handle->additive += val;
			}
		}
	}

private:
	ModifierUtilities() {}
};
