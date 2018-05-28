#pragma once

#include "components/modifiers/AdditiveModifier.hpp"

struct AdditiveLife : AdditiveModifier {
  AdditiveLife(int v) : AdditiveModifier(v) { id_ = "ADDITIVE_LIFE"; }
};
