/**
 * Tests boardgame creation and pathfinding algorithms.
 */
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
}
