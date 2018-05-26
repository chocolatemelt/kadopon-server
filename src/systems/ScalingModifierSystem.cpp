#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	entityx::ComponentHandle<Life> life;
	for(auto l : em.entities_with_components<Life>()) {
		l.unpack<Life>(life);
		life->base += 10;
		life->total = life->base;
	}
}
