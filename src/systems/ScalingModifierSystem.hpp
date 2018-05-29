/**
 * systems/ScalingModifierSystem.hpp
 * Generic system for scaling modifiers. Supports increased, reduced, more,
 * and less.
 */
#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entityx/entityx.h"
#include "utilities/ModifierUtilities.hpp"

class ScalingModifierSystem : public entityx::System<ScalingModifierSystem> {
public:
	ScalingModifierSystem() {}

	void update(entityx::EntityManager &em, entityx::EventManager &es, double dt);
};
