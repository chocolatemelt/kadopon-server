/**
 * Base Board class for use in game instances. Boards are standalone areas that can support multiple
 * players and contain references to Tiles.
 */
#pragma once

#include <string>
#include <unordered_map>

#include "misc/Constants.hpp"
#include "misc/Position.hpp"
#include "tiles/Tile.hpp"

class Board {
public:
  std::string name;
  int width, height;
  std::unordered_map<Position, Tile> board;

  /**
   * Basic Board constructor determines the name and size.
   * @param std::string name
   * @param int         width
   * @param int         height
   */
  Board(std::string n, int w, int h) : name(n), width(w), height(h), id_(constants::MISSING_BOARD) {}

  /**
   * Adds a tile to the board. If a tile exists at <x, y> position, replace that tile.
   * @param Position x, y position
   * @param Tile     Tile object to be added
   */
  void add_tile(Position, Tile);

  std::string id() { return id_; }

protected:
  std::string id_;
};
