/**
 * Base factory for registering Character entities, which include players and NPCs.
 */
#pragma once

#include "character/CharacterFactory.hpp"
#include "components/Attributes.hpp"
#include "misc/Types.hpp"

namespace Kadopon {
  namespace Character {
    /**
     * Creates a Player entity.
     * @param  reg entity registry
     * @return     newly created entity
     */
    Kadopon::Entity createPlayer(Kadopon::Registry &reg);
  }
}
