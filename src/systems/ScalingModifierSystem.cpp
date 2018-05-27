#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto m : em.entities_with_components<Life, IncreasedLife>()) {
		entityx::ComponentHandle<Life> life;
		entityx::ComponentHandle<IncreasedLife> incLife;
		m.unpack<Life>(life);
		m.unpack<IncreasedLife>(incLife);

		life->total = life->base * (1 + (incLife->total / 100.0));
		life->total = (int) life->total;
	}
}
