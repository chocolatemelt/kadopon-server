/**
 * Tests basic boardgame creation and pathfinding algorithms.
 */
#include <iostream>

#include "boards/Board.hpp"
#include "catch.hpp"
#include "misc/Position.hpp"
#include "tiles/Tile.hpp"

TEST_CASE("creates a board", "[boardgame][board][tile]") {
  std::string layout =
    "001000"
    "111111"
    "101010"
    "101010"
    "111011"
    "001000";
  Board test(layout, 6, 6);

  CHECK(19 == test.board.size());
  CHECK(!test.get(Position(0, 0))); // doesn't exist
  CHECK(test.get(Position(0, 1))); // does exist
}

TEST_CASE("properly wraps generic map functions", "[boardgame][board]") {
  std::string layout =
    "001000"
    "111111"
    "101010"
    "101010"
    "111011"
    "001000";
  Board test(layout, 6, 6);

  SECTION("can check if a board has a tile at given location") {
    CHECK(test.find(Position(0, 0)) == test.end());
    CHECK(test.find(Position(0, 2)) != test.end());
  }

  SECTION("can retrieve tiles and add them with [] operator") {
    CHECK(1 == test[Position(0, 2)].mv);

    CHECK(test.find(Position(0, 0)) == test.end());
    test[Position(0, 0)] = Tile();
    CHECK(test.find(Position(0, 0)) != test.end());
  }
}
