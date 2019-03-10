/**
 * This is the damage instance class. It will be the handler of damage
 */
#include "Chara.hpp"


DamageInstance::DamageInstance() {
  Chara;
}

//Physical attack done on to character
int DamageInstance::physAtk(int d, Chara c) {
  int hp = c.hp;
  int full_damage = c.action1;
  int reduced_damage = full_damage - c.block;
  return hp-reduced_damage;
}

//Fire attack done on to character
int DamageInstance::fireAtk(int d, Chara c) {
  int hp = c.hp;
  int full_damage = c.action1;
  int reduced_damage = full_damage - c.fres;
  return hp-reduced_damage;
}

//Cold attack done on to character
int DamageInstance::coldAtk(int d, Chara c) {
  int hp = c.hp;
  int full_damage = c.action1;
  int reduced_damage = full_damage - c.cres;
  return hp-reduced_damage;
}

//Light attack done on to character
int DamageInstance::ligtAtk(int d, Chara c) {
  int hp = c.hp;
  int full_damage = c.action1;
  int reduced_damage = full_damage - c.lres;
  return hp-reduced_damage;
}
