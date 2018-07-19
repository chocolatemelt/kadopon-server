/**
 * tests/random/movement.cpp
 * Basic movement tests.
 */

#include <random>
#include <iostream>
#include <map>

#include "catch.hpp"
#include "utilities/RandomUtilities.hpp"

TEST_CASE("Die distribution hits 0-6", "[random]") {
	std::mt19937 gen;
    std::map<int, int> rolldist;
    for(int i=0; i<10000; ++i) {
        ++rolldist[rolldie(gen)];
    }
    for(auto r : rolldist) {
        std::cout << r.first << ' ' << std::string(r.second/100, '*') << '\n';
    }

    REQUIRE(rolldist.find(0) > 0);
    REQUIRE(rolldist.find(0) < 1000);
    REQUIRE(rolldist.find(1) > 0);
    REQUIRE(rolldist.find(1) < 1000);
    REQUIRE(rolldist.find(2) > 500);
    REQUIRE(rolldist.find(2) < 1500);
    REQUIRE(rolldist.find(3) > 2000);
    REQUIRE(rolldist.find(3) < 3000);
    REQUIRE(rolldist.find(4) > 2000);
    REQUIRE(rolldist.find(4) < 3000);
    REQUIRE(rolldist.find(5) > 1500);
    REQUIRE(rolldist.find(5) < 2500);
    REQUIRE(rolldist.find(6) > 500);
    REQUIRE(rolldist.find(6) < 1500);
}