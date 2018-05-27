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
		else if(uid == "MORE_MAX_LIFE") {
			if(std::is_base_of<ScalingComponent, M>::value) {
				if(handle->multipliers.find(val) != handle->multipliers.end()) ++handle->multipliers[val];
				else handle->multipliers[val] = 1;
			}
		}
	}

	template <typename M>
	static void update_total(entityx::ComponentHandle<M> handle) {
		if(std::is_base_of<ScalingComponent, M>::value) {
			handle->total = (handle->base + handle->flat) * (1 + (handle->additive / 100.0));
			// apply more multipliers
			for(auto multi : handle->multipliers) {
				for(int i = 0; i < multi.second; ++i) handle->total *= 1 + (multi.first / 100.0);
			}
		}
	}

private:
	ModifierUtilities() {}
};
