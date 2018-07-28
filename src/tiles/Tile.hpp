/**
 * Base Tile class for Boards. Tiles are distinct objects that can only be traversed with sufficient
 * movement points, or a base movement roll of 6 (the highest base roll).
 */
#pragma once

#include <string>

#include "misc/Constants.hpp"

class Tile {
public:
  int mv;

  /**
   * Generic Tile constructor.
   */
  Tile() : mv(1), id_(constants::MISSING_TILE) {}

  std::string id() { return id_; }

protected:
  std::string id_;
};
