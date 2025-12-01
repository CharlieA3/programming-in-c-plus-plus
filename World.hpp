#ifndef WORLD_HPP
#define WORLD_HPP

#include "Point.hpp"
#include <list>
#include <set>



// struct that represents a square grid world with blocks, a start, and goal
struct World {
  int size; // size of the world: length of a side
  Point start; // start point for path
  Point goal; // goal point for path
  std::set<Point> blocks; // blocks that cannot be traversed

  // create a random world based on the given seed.
  void initialize(int worldId);

  // display the world and the given path (if any) through it.
  // blocks are displayed as 'X', the start as 'S', and the goal as 'G'.
  // if a block, start, or goal is in the path it is displayed lowercase ('x', 's', or 'g').
  // otherwise, if a point is in the path it is displayed as '.' and if not on the path as a space ' '.
  // points on a line are separated by spaces.
  // There's a space between printed columns
  void display(const std::list<Point> & path) const;

  // get the neighbors for a given point; neighbor are put in the set.
  // potential neighbors for a point are the points to the left, right, up and down of the given point (not diagonals).
  // however, if a potential neighbor is a block or off the world, it is not a neighbor.
  // additionally, points that are off the world or blocks themselves have no neighbors.
  void get_neighbors(const Point & p, std::set<Point> & neighbors) const;
};



#endif
