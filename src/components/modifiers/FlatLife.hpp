#pragma once

#include "components/modifiers/FlatModifier.hpp"

struct FlatLife : FlatModifier {
  FlatLife(int v) : FlatModifier(v) { id_ = "FLAT_LIFE"; }
};
