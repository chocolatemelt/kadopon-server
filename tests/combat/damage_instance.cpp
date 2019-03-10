/**
 * Test damage instances
 */

#include "combat/DamageInstance.hpp"
#include "combat/Chara.hpp"
#include <iostream>
#include <string>


TEST_CASE("creates a damage", "[damage][instance]") {

  /* code */


  DamageInstance * di = new DamageInstance();
  Chara cPhys = new Chara();
  Chara cFire = new Chara();
  Chara cCold = new Chara();
  Chara cLigh = new Chara();

  //may become an object
  int damageSource = 0;
  int phys = -1;
  int fire = -1;
  int cold = -1;
  int ligh = -1;

  phys = di->physAtk(damageSource,cPhys);
  fire = di->fireAtk(damageSource,cFire);
  cold = di->coldAtk(damageSource,cCold);
  ligh = di->ligtAtk(damageSource,cLigh);

  std::cout << "phys "<< phys<<std::endl;
  std::cout << "fire "<< fire<<std::endl;
  std::cout << "cold "<< cold<<std::endl;
  std::cout << "ligh "<< ligh<<std::endl;

  CHECK(phys!=-1);
  CHECK(fire!=-1);
  CHECK(cold!=-1);
  CHECK(ligh!=-1);
  
  }
