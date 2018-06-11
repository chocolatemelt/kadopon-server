/**
 * Collection of all core attributes, i.e. attributes directly used by the game.
 */
#pragma once

#include "components/attributes/Attribute.hpp"

struct Life : Attribute {};
struct Mana : Attribute {};
struct LifeRegen : Attribute{};
struct ManaRegen : Attribute{};
struct Armour : Attribute{};
struct Evasion : Attribute{};
struct Accuracy : Attribute{};
struct Block : Attribute{};
struct Dodge : Attribute{};
struct FireResist : Attribute{};
struct ColdResist : Attribute{};
struct LightResist : Attribute{};
struct CritChance : Attribute{};
struct CritMulti : Attribute{};
