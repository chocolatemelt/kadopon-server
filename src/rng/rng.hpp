/**
 * rng.hpp
 * Simple random number generator using C++11 STL, with support for custom probability
 * distributions.
 */
#pragma once

#include "xorshift.hpp"

class Rng {
public:
  static int get();
private:
  Rng() {}
};
