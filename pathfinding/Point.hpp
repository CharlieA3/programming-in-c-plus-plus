#ifndef POINT_HPP
#define POINT_HPP



// struct representing a point
struct Point {
  int row, col;
};

// operators for comparing points
bool operator<(const Point & lhs, const Point & rhs); // needed for set and map
bool operator==(const Point & lhs, const Point & rhs);
bool operator!=(const Point & lhs, const Point & rhs);



#endif
