/**
 * Tests boardgame creation and pathfinding algorithms.
 */
#include "boards/Board.hpp"
#include "catch.hpp"
#include "misc/Position.hpp"
#include "tiles/Tile.hpp"

TEST_CASE("creates a board", "[boardgame][board][tile]") {
  Board board("Forest", 10, 10);

  board.add_tile(Position(0, 0), Tile());
}
