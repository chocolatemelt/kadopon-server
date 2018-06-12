/**
 * Tests Position objects.
 */
 #include <boost/range/irange.hpp>
#include <unordered_map>

#include "catch.hpp"
#include "misc/Position.hpp"

TEST_CASE("Position has no collisions", "[misc][position]") {
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
