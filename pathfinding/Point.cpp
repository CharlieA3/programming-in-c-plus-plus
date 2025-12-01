#include "Point.hpp"



bool operator<(const Point & lhs, const Point & rhs) {
  if (lhs.row < rhs.row) return true;
  if (lhs.row > rhs.row) return false;
  if (lhs.col < rhs.col) return true;
  if (lhs.col > rhs.col) return false;
  return false;
}

bool operator==(const Point & lhs, const Point & rhs) {
  return !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const Point & lhs, const Point & rhs) {
  return !(lhs == rhs);
}
