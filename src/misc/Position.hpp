/**
 * Generic Position object.
 */
#pragma once

#include <vector>

struct Position {
  int x;
  int y;

  Position(int x, int y) : x(x), y(y) {}

  Position north() { return Position(x, y + 1); }
  Position south() { return Position(x, y - 1); }
  Position east() { return Position(x + 1, y); }
  Position west() { return Position(x - 1, y); }

  std::vector<Position> get_neighbors() {
    std::vector<Position> ret;
    ret.push_back(north());
    ret.push_back(south());
    ret.push_back(east());
    ret.push_back(west());
    return ret;
  }

  bool operator==(const Position &rhs) const {
    return (
      x == rhs.x
      && y == rhs.y
    );
  }

  bool operator!=(const Position &rhs) const {
    return !(*this == rhs);
  }
};

namespace std {
  template <>
  struct hash<Position> {
    std::size_t operator()(const Position &p) const {
      int hash = 17;
      int hashx = ((hash + p.x) << 5) - (hash + p.x);
      int hashy = ((hash + p.y) << 5) - (hash + p.y);
      return hashx ^ hashy;
    }
  };
}
