/**
 * Various utility functions for the boardgame.
 */
#pragma once

#include <set>

#include "boards/Board.hpp"
#include "misc/Position.hpp"

class BoardgameUtilities {
public:
  /**
   * Finds the set of tiles reachable by the given amount of movement points on a board.
   * @param  Position      start position
   * @param  Board         board
   * @param  int           movement points
   * @param  set<Position> set of tiles used in recursion
   * @return               set of tiles given as their position on the board
   */
  static std::set<Position> pathfinder(Position, Board, int, std::set<Position> &);

private:
  BoardgameUtilities() {}

  static void pathfinder_helper(Position, Position, Board, int, std::set<Position> &);
};
