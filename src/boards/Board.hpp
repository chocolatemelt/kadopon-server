/**
 * Base Board class for use in game instances. Boards are standalone areas that can support multiple
 * players and contain references to Tiles.
 */
#pragma once

#include <string>
#include <unordered_map>

#include "misc/Position.hpp"

class Board {
public:
  std::string name;
  int width, height;
  std::unordered_map

  /**
   * Basic Board constructor determines the name and size.
   * @param std::string name
   * @param int         width
   * @param int         height
   */
  Board(std::string n, int w, int h) : name(n), width(w), height(h) {}

  std::string id() { return id_; }

protected:
  std::string id_;
};
