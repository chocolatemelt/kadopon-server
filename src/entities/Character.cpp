#include "entities/Character.hpp"

std::vector<Modifier> Character::testGetModifier(std::string id) {
	std::vector<Modifier> ret;
	for(Modifier mod : modifiers) {
		if(id == mod.getId()) {
			ret.push_back(mod);
		}
	}
	return ret;
}
