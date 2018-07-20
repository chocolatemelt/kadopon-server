/**
 * Creates a Kadopon game instance, initializing all the relevant objects required for the beginning
 * of the game.
 */
#pragma once

#include "entityx/entityx.h"

class GameInstance {
public:
  entityx::EventManager events;
  entityx::EntityManager entities;
  entityx::SystemManager systems;

  GameInstance() : events(), entities(events), systems(entities, events) {}
};
