#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto m : em.entities_with_components<Life>()) {
		entityx::ComponentHandle<Life> life;
		m.unpack<Life>(life);

		life->total = (life->base + life->flat) * (1 + (life->additive / 100.0));
		life->total = static_cast<int>(life->total);
	}
}
