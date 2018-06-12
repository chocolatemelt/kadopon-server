/**
 * Generic Position object.
 */
#pragma once

struct Position {
  int x;
  int y;

  Position(int x, int y) : x(x), y(y) {}

  bool operator==(const Position &rhs) const {
    return (
      x == rhs.x
      && y == rhs.y
    );
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
