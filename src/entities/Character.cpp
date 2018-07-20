#include "components/attributes/Attributes.hpp"
#include "entities/Character.hpp"

Character::Character(entityx::Entity e) : ref(e) {
  ref.assign<Life>();
}
