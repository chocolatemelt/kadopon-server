/**
 * components/modifiers/Modifier.hpp
 * Modifier components track the total for any given modifier.
 */
#pragma once

#include <string>

#include "entityx/entityx.h"

struct Modifier : entityx::Component<Modifier> {
	int total;

	Modifier(int t) : total(t) {}

protected:
	std::string uid; // don't want this changing at all; identifies the modifier itself
};
