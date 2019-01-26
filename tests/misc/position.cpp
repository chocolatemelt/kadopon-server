/**
 * Tests Position objects.
 */
#include <boost/range/irange.hpp>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "catch.hpp"
#include "misc/Position.hpp"

TEST_CASE("position fits into map", "[misc][position]") {
  std::unordered_map<Position, int> collider;
  for(int x : boost::irange(0, 100)) {
    for(int y : boost::irange(0, 100)) {
      collider.emplace(Position(x, y), x + y);
    }
  }
  for(int x : boost::irange(0, 100)) {
    for(int y : boost::irange(0, 100)) {
      CHECK(collider.at(Position(x, y)) == x + y);
    }
  }
}

TEST_CASE("position equality", "[misc][position]") {
  CHECK(Position(0, 0) == Position(0, 0));
  CHECK(Position(0, 0) != Position(1, 1));
  CHECK(Position(-1, -1) != Position(1, 1));
}

TEST_CASE("position gets neighbors", "[misc][position]") {
  Position base = Position(0,0);
  std::vector<Position> neighbors = base.get_neighbors();
  std::unordered_set<Position> check;
  check.insert(base.north());
  check.insert(base.south());
  check.insert(base.east());
  check.insert(base.west());

  for(auto pos : neighbors) {
    CHECK(check.find(pos) != check.end());
  }
}
