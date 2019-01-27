#include "utilities/BoardgameUtilities.hpp"

void BoardgameUtilities::pathfinder(Position start,
                                    Board board,
                                    int mv,
                                    std::unordered_set<Position> &ret) {
  if(mv) {
    // check neighboring tiles
    for(auto pos : start.get_neighbors()) {
      Tile *next = board.get(pos);
      // ensure we're not looking at nonexistent tiles
      if(next) {
        pathfinder(pos, start, board, mv - next->mv, ret);
      }
    }
  }
  else {
    // add the current position to the return set if we can't move any further
    ret.insert(start);
  }
}

void BoardgameUtilities::pathfinder(Position start,
                                    Position last,
                                    Board board,
                                    int mv,
                                    std::unordered_set<Position> &ret) {
  if(mv) {
    // check neighboring tiles
    for(auto pos : start.get_neighbors()) {
      Tile *next = board.get(pos);
      // ensure we're not looking at nonexistent tiles or moving backwards...
      if(next && pos != last) {
        pathfinder(pos, start, board, mv - next->mv, ret);
      }
    }
  }
  else {
    // add the current position to the return set if we can't move any further
    ret.insert(start);
  }
}
