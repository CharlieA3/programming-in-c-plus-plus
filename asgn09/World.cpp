#include "World.hpp"
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

void World::initialize(int worldId)
{
  mt19937 mt_rand(worldId);

  size = 10 + int(mt_rand() % 10);

  start = {int(mt_rand() % size), int(mt_rand() % size)};
  do
  {
    goal = {int(mt_rand() % size), int(mt_rand() % size)};
  } while (start == goal);

  int nblocks = size * size / 3;
  for (int ii = 0; ii < nblocks; ++ii)
  {
    Point block = {int(mt_rand() % size), int(mt_rand() % size)};
    if (block != start && block != goal)
    {
      blocks.insert(block);
    }
  }
}

void World::display(const list<Point> &path) const
{
  // for columns and rows print out stuff depening on if it is in the path, start, goal, etc
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      Point temp_point = {i, j};
      // if this temporary point is equal to start
      if (temp_point == start)
      {
        // check if start is inside the path
        find(path.begin(), path.end(), temp_point) != path.end() ? cout << 's' : cout << "S";
      }
      else if (temp_point == goal)
      {
        find(path.begin(), path.end(), temp_point) != path.end() ? cout << 'g' : cout << "G";
      }
      else if (blocks.contains(temp_point))
      {
        // if we find the current point in the list of blocks print
        find(path.begin(), path.end(), temp_point) != path.end() ? cout << 'x' : cout << 'X';
      }
      else
      {
        find(path.begin(), path.end(), temp_point) != path.end() ? cout << '.' : cout << ' ';
      }
      // space everything out with a space
      if (j != size - 1)
      {
        cout << ' ';
      }
    }
    cout << endl;
  }
}

void World::get_neighbors(const Point &p, set<Point> &neighbors) const
{
  neighbors.clear();

  if (p.row < 0 || p.row >= size || p.col < 0 || p.col >= size)
  {
    return;
  }

  if (blocks.contains(p))
  {
    return;
  }

  const Point potential_neighbors[4] = {
      {p.row - 1, p.col},
      {p.row + 1, p.col},
      {p.row, p.col - 1},
      {p.row, p.col + 1}};

  for (auto point : potential_neighbors)
  {
    // off the world
    if (point.row < 0 || point.row >= size || point.col < 0 || point.col >= size)
    {
      continue;
    }

    if (blocks.contains(point))
    {
      continue;
    }
    neighbors.insert(point);
  }
}
