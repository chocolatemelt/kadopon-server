/**
 * Base Board class for use in game instances. Boards are standalone areas that can support multiple
 * players and contain references to Tiles.
 */
#pragma once

#include <string>
#include <unordered_map>
#include <utility>

#include "misc/Constants.hpp"
#include "misc/Position.hpp"
#include "tiles/Tile.hpp"

class Board {
public:
  std::string name;
  int width, height;
  std::unordered_map<Position, Tile> board;

  /**
   * Basic Board constructor for internal testing; only uses generic MISSING_TILES.
   * A layout string must be composed of 0s (no tile) and 1s (tile). The string length must be
   * exactly the width * height.
   * @param std::string layout
   */
  Board(std::string, int, int);

  /**
   * Adds a tile to the board. If a tile exists at <x, y> position, replace that tile.
   * @param Position x, y position
   * @param Tile     Tile object to be added
   */
  void add_tile(Position, Tile);

  /**
   * Retrieves the Tile at Position if it exists.
   * @param  Position position
   * @return          pointer to Tile at Position
   */
  Tile* get(Position);

  /**
   * Returns this board's private ID.
   * @return private id
   */
  std::string id() { return id_; }

  // common map functions to wrap around
  std::unordered_map<Position, Tile>::iterator find(const Position &p) {
    return board.find(p);
  }

  std::unordered_map<Position, Tile>::iterator begin() {
    return board.begin();
  }

  std::unordered_map<Position, Tile>::iterator end() {
    return board.end();
  }

  Tile& operator[](const Position &p) {
    return board[p];
  }

  Tile& operator[](Position &&p) {
    return board[std::move(p)];
  }

protected:
  std::string id_;
};
