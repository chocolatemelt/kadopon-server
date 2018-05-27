/**
 * systems/ScalingModifierSystem.hpp
 * Generic system for scaling modifiers. Supports increased, reduced, more,
 * and less.
 */
#include "components/Life.hpp"
#include "components/Mana.hpp"
#include "entityx/entityx.h"
#include "utilities/ModifierUtilities.hpp"

class ScalingModifierSystem : public entityx::System<ScalingModifierSystem> {
public:
	ScalingModifierSystem() {}

	void update(entityx::EntityManager &em, entityx::EventManager &es, double dt);
};
