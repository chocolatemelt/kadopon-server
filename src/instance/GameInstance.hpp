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

  /**
   * GameInstance default constructor. Sets up a Kadopon game with default values.
   */
  GameInstance();

  /**
   * Updates scaling modifiers for all relevant characters.
   */
  void update_modifiers();
  void update_modifiers(double);
};
