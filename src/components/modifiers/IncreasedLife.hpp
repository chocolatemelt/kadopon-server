/**
 * components/modifiers/IncreasedModifier.hpp
 * Base class for increased modifiers, which are additive multipliers. This also covers the
 * converse, reduced modifiers (which are naturally subtractive multipliers instead).
 */
#pragma once

#include "components/modifiers/Modifier.hpp"

struct IncreasedLife : Modifier {
	IncreasedLife(int t) : Modifier(t) {
		uid = "INC_MAX_LIFE";
	}
};
