#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto m : em.entities_with_components<Life>()) {
		entityx::ComponentHandle<Life> life;
		m.unpack<Life>(life);

		life->total = life->base * (1 + (life->additive_modifier / 100.0));
		life->total = (int) life->total;
	}
}
