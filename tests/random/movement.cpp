/**
 * tests/random/movement.cpp
 * Basic movement tests.
 */

#include <random>
#include <iostream>
#include <map>
#include <vector>

#include "catch.hpp"
#include "utilities/Random.hpp"

TEST_CASE("Die distribution hits 0-6", "[random]") {
  std::map<int, int> rolls;

  for(auto x : Random::roll_movement(10000)) {
    ++rolls[x];
  }

  // print distribution
  for(auto r : rolls) {
    std::cout << r.first << ' ' << std::string(r.second/100, '*') << std::endl;
  }

  // distributions are within 1% of expected result
  CHECK(rolls.find(0)->second > 400);
  CHECK(rolls.find(0)->second < 600);
  CHECK(rolls.find(1)->second > 400);
  CHECK(rolls.find(1)->second < 600);
  CHECK(rolls.find(2)->second > 900);
  CHECK(rolls.find(2)->second < 1100);
  CHECK(rolls.find(3)->second > 2400);
  CHECK(rolls.find(3)->second < 2600);
  CHECK(rolls.find(4)->second > 2400);
  CHECK(rolls.find(4)->second < 2600);
  CHECK(rolls.find(5)->second > 1900);
  CHECK(rolls.find(5)->second < 2100);
  CHECK(rolls.find(6)->second > 900);
  CHECK(rolls.find(6)->second < 1100);
}
