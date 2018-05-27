#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	// use .each() instead here... later
	for(auto m : em.entities_with_components<ModifierList>()) {
		entityx::ComponentHandle<ModifierList> mods_;
		m.unpack<ModifierList>(mods_);
		for(auto l : em.entities_with_components<Life>()) {
			entityx::ComponentHandle<Life> life;
			l.unpack<Life>(life);

			// shitty code for proof of concept scaling with modifiers
			// this calculates it like "more" lol
			for(auto mod : mods_->modifiers) {
				if(mod.getId() == "MAXIMUM_LIFE") {
					life->total *= 1.1;
				}
			}
			life->total = (int) life->total;
		}
		for(auto s : em.entities_with_components<Mana>()) {
			entityx::ComponentHandle<Mana> sc;
			s.unpack<Mana>(sc);
		}
	}
}
