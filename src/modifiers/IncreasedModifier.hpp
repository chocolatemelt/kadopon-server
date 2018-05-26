/**
 * modifiers/IncreasedModifier.hpp
 * Base class for increased modifiers, which are additive multipliers. This also covers the
 * converse, reduced modifiers (which are naturally subtractive multipliers instead).
 */
#pragma once

#include "modifiers/Modifier.hpp"

template <typename T>
struct IncreasedModifier : Modifier {
	IncreasedModifier(std::string id, T v) : Modifier(id), value(v) {}

	T value;
};
