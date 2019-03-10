/**
 * Damage hpp
 */
#pragma once


#include "Chara.hpp"
//include some character
//include some skil

class DamageInstance {
public:
  Chara chara;

  //DamageInstance constructor starts up an instance for players or monsters to be damaged
  DamageInstance();

  //in the future d might be the damage and its effects onto the Character
  //for now using character values to emulate it
  int physAtk(int d, Chara c);
  int fireAtk(int d, Chara c);
  int coldAtk(int d, Chara c);
  int ligtAtk(int d, Chara c);

};
