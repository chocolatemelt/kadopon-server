#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto m : em.entities_with_components<Life>()) {
		entityx::ComponentHandle<Life> life;
		m.unpack<Life>(life);

		ModifierUtilities::update_total(life);
	}
}
