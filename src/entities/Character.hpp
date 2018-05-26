/**
 * entities/Character.hpp
 * Simple entity container for a Character - does not make a particular distinction between Player
 * and NPC characters.
 */
#pragma once

#include <string>
#include <vector>

#include "entityx/entityx.h"
#include "modifiers/Modifier.hpp"

class Character : public entityx::Entity {
public:
	Character(std::string n) : name(n) {}

	template <class Mod>
	void testAddModifier(Mod m) {
		modifiers.push_back(m);
	}

	std::vector<Modifier> testGetModifier(std::string id);

private:
	std::string name;
	std::vector<Modifier> modifiers;
};
