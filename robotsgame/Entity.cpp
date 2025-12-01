#include "Entity.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

// n_counter(nullptr) is a member initializer list, which initializes m_counter to be a null pointer
Player::Player(const Cell &cell, const EntityCounter &counter) : m_counter(counter)
{
  // makes a player at the given cell (row, col)
  m_cell.col = cell.col;
  m_cell.row = cell.row;
  // used entity counter variables to count the number of players that exist
  // I think we are initializing it as nullptr because we can then assign it to the passed in entity counter and increment it
  m_counter.increment();
}

// this will happen when you assign p1 = p2, we want to copy the cell but have the same counter
// if both the copy player and the player get destructed, we will try to double free? I guess this isn't allocated on the heap so we're good?
Player::Player(const Player &other) : m_counter(other.m_counter)
{
  // this players cell assigned to the copy player that we are creating
  m_cell = other.m_cell;
  m_counter.increment();
}

Player::~Player()
{
  m_counter.decrement();
}

// I am zero indexing
void Player::update(Direction input_direction, size_t worldRows, size_t worldCols)
{
  switch (input_direction)
  {
  case Direction::north:
    // if the player is at the top of the world and they enter north, they can't move up
    m_cell.row != 1 ? m_cell.row-- : m_cell.row;
    break;
  case Direction::south:
    m_cell.row != worldRows ? m_cell.row++ : m_cell.row;
    break;
  case Direction::east:
    m_cell.col != worldCols ? m_cell.col++ : m_cell.col;
    break;
  case Direction::west:
    m_cell.col != 1 ? m_cell.col-- : m_cell.col;
    break;
  case Direction::none:
    break;
  }
}

const Cell &Player::get_cell() const
{
  return m_cell;
}

RobotOrDebris::RobotOrDebris(const Cell &cell, bool isDebris, const EntityCounter &counter) : m_counter(counter)
{
  m_cell.col = cell.col;
  m_cell.row = cell.row;
  m_isDebris = isDebris;
  // I think this is right, but maybe I can jsut replace the nullptr initializer with the value being passed in
  m_counter.increment();
}

// copy constructor
RobotOrDebris::RobotOrDebris(const RobotOrDebris &other) : m_counter(other.m_counter)
{
  m_cell.col = other.m_cell.col;
  m_cell.row = other.m_cell.row;
  m_isDebris = other.m_isDebris;
  // I think I still want to increment here, because two robots will be destroyted decrementing entity count by 2 and then this will be copies, incrementing by 1
  m_counter.increment();
}

RobotOrDebris::~RobotOrDebris()
{
  m_counter.decrement();
}

// since the logic for never being able to go out of bounds is in the player, and the robot is following the player, I don't need duplicate logic for the robot staying in bounds
void RobotOrDebris::update(const Player &player)
{
  int dist_from_p_row;
  int dist_from_p_col;
  int north_south;
  int west_east;
  // if cell location of robot and player are equal, do nothing
  if (m_cell == player.get_cell())
    return;

  // I think the origin (0,0), but this will tell us which direction the robot needs to move and the magnitude of each direction two negative numbers like (-2, -2) for row and
  // column means that the robot needs to move up and left (or north and west)
  dist_from_p_row = player.get_cell().row - m_cell.row;
  dist_from_p_col = player.get_cell().col - m_cell.col;

  dist_from_p_col < 0 ? west_east = -1 : west_east = 1;

  dist_from_p_row < 0 ? north_south = -1 : north_south = 1;

  // if in the same row or column adjust by the west_east and north_south variables
  if (dist_from_p_row == 0)
  {
    m_cell.col += west_east;
    return;
  }
  if (dist_from_p_col == 0)
  {
    m_cell.row += north_south;
    return;
  }

  (m_cell.row + m_cell.col) % 2 == 0 ? m_cell.row += north_south : m_cell.col += west_east;

  // 0 0  ->  (west, north)  ->  no checks for if the robot is in the same row or column
  // 0 1  ->  (west, south)  -> check if robot is in the same column
  // 1 0  ->  (east, north)  -> check if the robot is in the same row
  // 1 1  ->  (east, south)  -> check if the robot is in the same row or the same column
}

const Cell &RobotOrDebris::get_cell() const
{
  return m_cell;
}

void RobotOrDebris::make_debris()
{
  m_isDebris = true;
}

bool RobotOrDebris::is_debris() const
{
  return m_isDebris;
}