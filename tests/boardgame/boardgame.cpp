/**
 * Tests basic boardgame creation and pathfinding algorithms.
 */
#include <iostream>
#include <unordered_set>

#include "boards/Board.hpp"
#include "catch.hpp"
#include "misc/Position.hpp"
#include "tiles/Tile.hpp"
#include "utilities/BoardgameUtilities.hpp"

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
  CHECK(test.get(Position(0, 2))); // does exist
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

TEST_CASE("pathfinder algorithm finds end tiles", "[boardgame][board][algorithm][tile]") {
  std::string layout =
    "001000"
    "111111"
    "101010"
    "101010"
    "111011"
    "001000";
  Board test(layout, 6, 6);

  SECTION("finds the end tiles from (0, 2)") {
    std::unordered_set<Position> check;
    BoardgameUtilities::pathfinder(Position(0, 2), test, 2, check);

    CHECK(check.size() == 3);
    CHECK(check.find(Position(1, 3)) != check.end());
    CHECK(check.find(Position(2, 2)) != check.end());
    CHECK(check.find(Position(1, 1)) != check.end());
  }

  SECTION("finds self tile with no movement roll") {
    std::unordered_set<Position> check;
    BoardgameUtilities::pathfinder(Position(0, 2), test, 0, check);

    CHECK(check.size() == 1);
    CHECK(check.find(Position(0, 2)) != check.end());
  }
}
