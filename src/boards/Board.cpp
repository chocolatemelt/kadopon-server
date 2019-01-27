#include <boost/range/irange.hpp>

#include "boards/Board.hpp"

Board::Board(std::string layout, int w, int h) : name("Generic"), width(w), height(h), id_(constants::MISSING_BOARD) {
  // starting from the bottom left to the top right corner
  for(int x : boost::irange(0, w)) {
    for(int y : boost::irange(0, h)) {
      if(layout[x * w + y] == '1') board[Position(x, y)] = Tile();
    }
  }
}

void Board::add_tile(Position pos, Tile t) {
  if(pos.x >= 0 && pos.x < width &&
     pos.y >= 0 && pos.y < height) {
       board[pos] = t;
     }
}

Tile *Board::get(Position pos) {
  if(board.find(pos) != board.end()) {
    return &board[pos];
  }
  return nullptr;
}
