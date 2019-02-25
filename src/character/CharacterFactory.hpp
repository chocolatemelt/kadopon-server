/**
 * Base factory for registering Character entities, which include players and NPCs.
 */
#pragma once

#include "character/CharacterFactory.hpp"
#include "components/Attributes.hpp"
#include "misc/Types.hpp"

namespace Character {
  /**
   * Creates a character entity.
   * @param  reg entity registry
   * @return     newly created entity
   */
  Entity createCharacter(Registry &reg);
}
