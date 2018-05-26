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

class Character {
public:
	Character(std::string n, entityx::Entity e) : name(n), entity(e) {}

	template <class Mod>
	void testAddModifier(Mod m) {
		modifiers.push_back(m);
	}

private:
	std::string name;
	entityx::Entity entity;
	std::vector<Modifier> modifiers;
};
