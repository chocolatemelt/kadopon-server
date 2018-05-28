/**
 * utilities/ModifierUtilities.hpp
 * Various utility functions for managing modifiers.
 */
#pragma once

#include <cmath>
#include <string>
#include <type_traits>

#include "components/ScalingComponent.hpp"
#include "entityx/entityx.h"

class ModifierUtilities {
public:
	template <typename M>
	static void add_flat_mod(entityx::ComponentHandle<M> handle, int val) {
		if(std::is_base_of<ScalingComponent, M>::value) {
			handle->flat += val;
		}
	}

	template <typename M>
	static void add_additive_mod(entityx::ComponentHandle<M> handle, int val) {
		if(std::is_base_of<ScalingComponent, M>::value) {
			handle->additive += val;
		}
	}

	template <typename M>
	static void add_multiplicative_mod(entityx::ComponentHandle<M> handle, int val) {
		if(std::is_base_of<ScalingComponent, M>::value) {
			// multiplicative modifiers are held in a map with their count; simply increment if it exists
			if(handle->multipliers.find(val) != handle->multipliers.end()) ++handle->multipliers[val];
			else handle->multipliers[val] = 1;
		}
	}

	template <typename M>
	static void update_total(entityx::ComponentHandle<M> handle) {
		if(std::is_base_of<ScalingComponent, M>::value) {
			handle->total = (handle->base + handle->flat) * (1 + (handle->additive / 100.0));
			// apply more multipliers separately, based on their count
			for(auto multi : handle->multipliers) {
				handle->total *= std::pow((1 + (multi.first / 100.0)), multi.second);
			}
		}
	}

private:
	ModifierUtilities() {}
};
