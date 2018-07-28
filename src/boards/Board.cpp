#include <boost/range/irange.hpp>

#include "boards/Board.hpp"

Board::Board(std::string layout, int w, int h) : name("Generic"), width(w), height(h), id_(constants::MISSING_BOARD) {
  // starting from the bottom left to the top right corner
  for(int y : boost::irange(0, h)) {
    for(int x : boost::irange(0, w)) {
      if(layout[x + y * w] == '1') board[Position(x, y)] = Tile();
    }
  }
}

void Board::add_tile(Position pos, Tile t) {
  if(pos.x >= 0 && pos.x < width &&
     pos.y >= 0 && pos.y < height) {
       board[pos] = t;
     }
}
