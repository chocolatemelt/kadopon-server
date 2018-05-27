/**
 * utilities/ModifierUtilities.hpp
 * Various utility functions for managing modifiers.
 */
#include "components/ModifierList.hpp"
#include "entityx/entityx.h"

class ModifierUtilities {
public:
	static int addModifier(entityx::Entity &e, Modifier m);
private:
	ModifierUtilities() {}
};
