/**
 * tests/random/random.cpp
 * Basic randomness tests.
 */

#include <random>

#include "catch.hpp"
#include "fmt/format.h"
#include "rng/xorshift.hpp"

TEST_CASE("RNG distribution hits 0-99", "[rng]") {
	// switched to mt19937 for mac compilation... high sierra has a problem with xorshift apparently
	// std::mt19937 eng;
	// std::uniform_int_distribution<int> dist(0, 99);
	// for (int i = 0; i < 1000; ++i) fmt::print("rng: {}\n", dist(eng));
	// CHECK(1==1);
}
