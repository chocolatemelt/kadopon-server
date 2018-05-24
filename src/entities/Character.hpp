#ifndef ENTITY_CHARACTER_H
#define ENTITY_CHARACTER_H

#include <string>

#include "entityx/entityx.h"

class Character {
public:
	Character(std::string n) : name(n) {}

	void initialize(entityx::ptr<entityx::EntityManager> entities,
									entityx::ptr<entityx::EventManager> events);

private:
	std::string name;

	entityx::Entity entity;
	entityx::ptr<entityx::EntityManager> entity_manager;
};

#endif
