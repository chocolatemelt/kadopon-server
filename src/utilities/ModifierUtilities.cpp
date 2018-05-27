#include "utilities/ModifierUtilities.hpp"

int ModifierUtilities::addModifier(entityx::Entity &e, Modifier m) {
	auto handler = e.component<ModifierList>();
	handler->modifiers.push_back(m);
	return handler->modifiers.size();
}
