/**
 * Temporary class for combat instance character. Can be player or monster.
 */
#pragma once

class Chara {
public:
    //health and mana
    int hp, mp;

    //health and mana regen
    int hregen, mregen;

    //armour, evasion
    int armour, evasion;

    //accuracy, block, dodge
    int acc, block, dodge;

    //elemental resistance
    int fres, cres, lres;

    //crit chance, crit multi
    int critchance, critmulti;

    //placeholders for actions such as weapon attack, spell, items
    int action1, action2, action3, action4;

    Chara::Chara() {
      hp = 100;
      mp = 100;
      hregen = 5;
      mregen = 5;

      armour = 20;
      evasion = 20;
      acc = 20;
      block = 20;
      dodge = 20;
      fres = 20;
      cres = 20;
      lres = 20;

      critchance = 5;
      critmulti = 2;

      //physical attack
      action1 = 50;
      //fire attack
      action2 = 50;
      //cold attack
      action3 = 50;
      //lightning attack
      action4 = 50;
    }
};
