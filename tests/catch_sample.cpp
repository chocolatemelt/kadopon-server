/**
 * tests/catch_sample.cpp
 * Description of what this file tests.
 */

#include "catch.hpp"

TEST_CASE("Catch", "[tags]") {
	SECTION("Test passes") {
		CHECK(1 == 1);
	}
}
