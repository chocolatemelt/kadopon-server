#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto l : em.entities_with_components<Life>()) {
		entityx::ComponentHandle<Life> life;
		l.unpack<Life>(life);
		life->base += 10;
		life->total = life->base;

		// shitty code for proof of concept scaling with modifiers
		// this calculates it like "more" lol
		// Character c = (Character) l;
		// for(auto m : c.testGetModifier("MAXIMUM_LIFE")) {
		// 	auto scaled = life->base * (1 + (((IncreasedModifier)m).value / 100.0))
		// 	life->total = scaled;
		// }
	}
	for(auto s : em.entities_with_components<Mana>()) {
		entityx::ComponentHandle<Mana> sc;
		s.unpack<Mana>(sc);
		sc->base += 10;
		sc->total = sc->base;
	}
}
