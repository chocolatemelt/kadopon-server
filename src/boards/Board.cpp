#include "boards/Board.hpp"

void Board::add_tile(Position pos, Tile t) {
  if(pos.x >= 0 && pos.x < width &&
     pos.y >= 0 && pos.y < height) {
       board[pos] = t;
     }
}
