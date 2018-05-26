/**
 * modifiers/Modifier.hpp
 * Base class for modifiers, which have a variety of different applications.
 */
#pragma once

#include <string>

struct Modifier {
	Modifier(std::string id) : uid(id) {}

	std::string getId() { return uid; }

private:
	std::string uid;
};
