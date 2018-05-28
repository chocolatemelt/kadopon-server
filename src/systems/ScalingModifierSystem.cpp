#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
	                                 entityx::EventManager &es,
																   double dt) {
	for(auto m : em.entities_with_components<Life, AdditiveLife, FlatLife, MultiplicativeLife>()) {
		// grab component handles
		entityx::ComponentHandle<Life> base;
		entityx::ComponentHandle<AdditiveLife> add;
		entityx::ComponentHandle<FlatLife> flat;
		entityx::ComponentHandle<MultiplicativeLife> multi;
		m.unpack<Life>(base);
		m.unpack<AdditiveLife>(add);
		m.unpack<FlatLife>(flat);
		m.unpack<MultiplicativeLife>(multi);

		ModifierUtilities::update_total(base, add, flat, multi);
	}
}
