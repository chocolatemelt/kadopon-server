#ifndef ENTITY_CHARACTER_H
#define ENTITY_CHARACTER_H

#include <string>

#include "entityx/entityx.h"

class Character {
public:
	Character(std::string n, entityx::Entity e) : name(n), entity(e) {}

private:
	std::string name;
	entityx::Entity entity;
};

#endif
