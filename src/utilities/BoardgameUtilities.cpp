#include "utilities/BoardgameUtilities.hpp"

std::set<Position> BoardgameUtilities::pathfinder(Position start,
                                                         Board board,
                                                         int mv,
                                                         std::set<Position> &ret) {
  if(mv) {
    // check neighboring tiles
    pathfinder_helper(start, start.north(), board, mv, ret);
    pathfinder_helper(start, start.south(), board, mv, ret);
    pathfinder_helper(start, start.east(), board, mv, ret);
    pathfinder_helper(start, start.west(), board, mv, ret);
  }
  else {
    return ret;
  }
}

void BoardgameUtilities::pathfinder_helper(Position start, Position check, Board board, int mv, std::set<Position> &ret) {
  if(start != check) {
    if(board.find(check) != board.end()) {
      int cost = mv - board[check].mv;
      if(cost) pathfinder(check, board, cost, ret);
      else {
        ret.insert(check)
        pathfinder(check, board, cost, ret);
      }
    }
  }
}
