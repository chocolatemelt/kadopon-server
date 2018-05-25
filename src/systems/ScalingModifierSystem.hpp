/**
 * systems/ScalingModifierSystem.hpp
 * Generic system for scaling modifiers. Supports increased, reduced, more,
 * and less.
 */
#include "components/Life.hpp"
#include "entityx/entityx.h"

class ScalingModifierSystem : public entityx::System<ScalingModifierSystem> {
public:
	ScalingModifierSystem();
	virtual ~ScalingModifierSystem();

	void update(entityx::EntityManager &em, entityx::EventManager &es, double dt);
};
