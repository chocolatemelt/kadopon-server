#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto l : em.entities_with_components<Life>()) {
		entityx::ComponentHandle<Life> life;
		l.unpack<Life>(life);
		life->base += 10;
		life->total = life->base;
	}
	for(auto s : em.entities_with_components<Mana>()) {
		entityx::ComponentHandle<Mana> sc;
		s.unpack<Mana>(sc);
		sc->base += 10;
		sc->total = sc->base;
	}
}
