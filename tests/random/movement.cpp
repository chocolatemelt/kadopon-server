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

using namespace Kadopon;

TEST_CASE("Die distribution hits 0-6", "[random]") {
  std::map<int, int> rolls;

  for(auto x : Random::roll_movement(10000)) {
    ++rolls[x];
  }

  // print distribution
  for(auto r : rolls) {
    std::cout << r.first << ' ' << std::string(r.second/100, '*') << std::endl;
  }

  // distributions are within 1.5% of expected result
  CHECK(rolls.find(0)->second > 350);
  CHECK(rolls.find(0)->second < 650);
  CHECK(rolls.find(1)->second > 350);
  CHECK(rolls.find(1)->second < 650);
  CHECK(rolls.find(2)->second > 850);
  CHECK(rolls.find(2)->second < 1150);
  CHECK(rolls.find(3)->second > 2350);
  CHECK(rolls.find(3)->second < 2650);
  CHECK(rolls.find(4)->second > 2350);
  CHECK(rolls.find(4)->second < 2650);
  CHECK(rolls.find(5)->second > 1850);
  CHECK(rolls.find(5)->second < 2150);
  CHECK(rolls.find(6)->second > 850);
  CHECK(rolls.find(6)->second < 1150);
}
