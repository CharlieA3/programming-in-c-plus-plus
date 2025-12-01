#include "Pathfinding.hpp"
#include "Point.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// utility function to compute a path from start to goal given the came_from information
void came_from_to_path(const map<Point, Point> &came_from, const Point &start, const Point &goal, list<Point> &path)
{
  path.clear();
  Point cur = goal;
  path.push_front(goal);

  while (cur != start)
  {
    map<Point, Point>::const_iterator iter = came_from.find(cur);
    if (iter == came_from.end())
    {
      path.clear();
      return;
    }
    // while the current point is not the start, make it the iterators element's value to use as the next key
    cur = iter->second;
    path.push_front(cur);
  }

  // if the goal or the start is not in the path, set path to empty and return (once we've exhausted our options)
  if (find(path.begin(), path.end(), start) == path.end() || find(path.begin(), path.end(), goal) == path.end())
  {
    path.clear();
  }
}

void pathfind_bfs(const World &w, list<Point> &path)
{
  path.clear();

  deque<Point> frontier;
  map<Point, Point> came_from;

  // put the first start in the deque
  // initialize came from dictionary to by empty
  frontier.push_back(w.start);

  while (!frontier.empty())
  {
    Point cur_p = frontier.front();
    // make sure to remove this from the queue once we get it
    frontier.pop_front();

    if (cur_p == w.goal)
    {
      break;
    }

    set<Point> cur_nei;
    w.get_neighbors(cur_p, cur_nei);

    for (auto pot_nei : cur_nei)
    {
      // use index for the potential neighbor to show that we can get to the potential neighbor form the current point
      // this works because when the path is reconstructed it goes in reverse
      // also don't want duplicates of neighbors
      if (came_from.find(pot_nei) != came_from.end() || pot_nei == w.start)
      {
        continue;
      }
      came_from[pot_nei] = cur_p;
      // still want to add each of the potential neighbor to the frontier
      frontier.push_back(pot_nei);
    }
  }

  came_from_to_path(came_from, w.start, w.goal, path);
}

// point for heap
struct PriorityPoint
{
  double priority;
  Point point;
};

// comparison for heap - lowest first!
bool operator<(const PriorityPoint &lhs, const PriorityPoint &rhs)
{
  return lhs.priority > rhs.priority;
}

// heuristic for A*
double heuristic(const Point &a, const Point &b)
{
  return abs(a.row - b.row) + abs(a.col - b.col);
}

// assume cost of moving is always 1
const double move_cost = 1.0;

void pathfind_astar(const World &w, list<Point> &path)
{
  path.clear();

  vector<PriorityPoint> frontier;
  map<Point, Point> came_from;
  map<Point, double> cost_so_far;

  // add the start point before looping
  PriorityPoint start_pri_p = {0, w.start};
  frontier.push_back(start_pri_p);
  make_heap(frontier.begin(), frontier.end());
  came_from[w.start] = w.start;
  cost_so_far[w.start] = 0;

  while (!frontier.empty())
  {
    // once we have the element we can remove it form the heapified vector
    pop_heap(frontier.begin(), frontier.end());
    PriorityPoint current = frontier.back();
    frontier.pop_back();

    if (current.point == w.goal)
    {
      break;
    }

    set<Point> cur_nei;
    w.get_neighbors(current.point, cur_nei);

    for (auto neighbor : cur_nei)
    {
      double new_cost = cost_so_far[current.point] + move_cost;

      if (neighbor == w.start)
      {
        continue;
      }

      if (cost_so_far.find(neighbor) == cost_so_far.end() || new_cost < cost_so_far[neighbor])
      {
        cost_so_far[neighbor] = new_cost;
        double priority = new_cost + heuristic(neighbor, w.goal);
        frontier.push_back({priority, neighbor});
        push_heap(frontier.begin(), frontier.end());
        came_from[neighbor] = current.point;
      }
    }
  }

  came_from_to_path(came_from, w.start, w.goal, path);
}