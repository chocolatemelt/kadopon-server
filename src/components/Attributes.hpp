/**
 * Attributes are the core building blocks of a character.
 */
#pragma once

namespace Attributes {
  struct Attribute {
    double current = 0;
    double maximum = 0;
  };

  struct Life : Attribute {};
  struct Mana : Attribute {};
  struct LifeRegen : Attribute {};
  struct ManaRegen : Attribute {};
  struct Armour : Attribute {};
  struct Evasion : Attribute {};
  struct Accuracy : Attribute {};
  struct Block : Attribute {};
  struct Dodge : Attribute {};
  struct FireRes : Attribute {};
  struct ColdRes : Attribute {};
  struct LightningRes : Attribute {};
  struct CritChance : Attribute {};
  struct CritMulti : Attribute {};
}
