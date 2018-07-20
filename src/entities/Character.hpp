/**
 * Character wrapper class. This is the base decorator for all interactable creatures, NPCs, and
 * players. Characters have stats, skills, items, and a bag.
 */
#pragma once

#include "entityx/entityx.h"

class Character {
public:
  entityx::Entity ref;

  /**
   * Character constructor requires an entity to be passed in (to decorate).
   * The Character constructor adds all required components on construction.
   * @param entityx::Entity entity
   */
  Character(entityx::Entity);
};
