/**
 * modifiers/Modifier.hpp
 * Base class for modifiers, which have a variety of different applications.
 */
#pragma once

#include <string>

struct Modifier {
	Modifier(std::string id) : uid(id) {}

private:
	std::string uid;
};
