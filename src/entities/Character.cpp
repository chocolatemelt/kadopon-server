#include "components/attributes/Attributes.hpp"
#include "entities/Character.hpp"

Character::Character(entityx::Entity e) : ref(e) {
  ref.assign<Life>();
  ref.assign<Mana>();
  ref.assign<LifeRegen>();
  ref.assign<ManaRegen>();
  ref.assign<Armour>();
  ref.assign<Evasion>();
  ref.assign<Accuracy>();
  ref.assign<Block>();
  ref.assign<Dodge>();
  ref.assign<FireRes>();
  ref.assign<ColdRes>();
  ref.assign<LightningRes>();
  ref.assign<CritChance>();
  ref.assign<CritMulti>();
}
