/**
 * systems/ScalingModifierSystem.hpp
 * Generic system for scaling modifiers. Supports increased, reduced, more,
 * and less.
 */
#include "components/Life.hpp"
#include "components/Mana.hpp"
#include "entities/Character.hpp"
#include "entityx/entityx.h"

class ScalingModifierSystem : public entityx::System<ScalingModifierSystem> {
public:
	ScalingModifierSystem() {}

	void update(entityx::EntityManager &em, entityx::EventManager &es, double dt);
};
