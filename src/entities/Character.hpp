/**
 * entities/Character.hpp
 * @param n name
 * @param e entity
 * Simple entity container for a Character - does not make a particular distinction between Player
 * and NPC characters.
 */
#pragma once

#include <string>

#include "entityx/entityx.h"

class Character {
public:
	Character(std::string n, entityx::Entity e) : name(n), entity(e) {}

private:
	std::string name;
	entityx::Entity entity;
};
