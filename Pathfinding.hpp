#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include "Point.hpp"
#include "World.hpp"
#include <list>



// for the following functions:
// given the world w, find the shortest path from the start to the
// goal and put it in path (path should include the start and goal
// points).  if there is no way to get from the start to the goal,
// path is set to empty.

// uses breadth-first search for pathfinding
void pathfind_bfs(const World & w, std::list<Point> & path);

// uses A* for pathfinding
void pathfind_astar(const World & w, std::list<Point> & path);



#endif
