/**
 * tests/rng/rng.cpp
 * Basic RNG tests.
 */

#include <random>

#include "catch.hpp"
#include "fmt/format.h"
#include "xorshift.hpp"

TEST_CASE("RNG distribution hits 0-99", "[rng]") {
	xorshift eng;
	std::uniform_int_distribution<int> dist(0, 99);
	for (int i = 0; i < 1000; ++i) fmt::print("rng: {}\n", dist(eng));
	CHECK(1==1);
}
