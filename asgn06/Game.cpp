#include "Game.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <map>
using namespace std;

const char *msg_filename = "Please enter a world file:";
const char *msg_direction = "Please enter a direction to move (wasd or space):";

const char *errmsg_world_file = "Error reading world file.";
const char *errmsg_world_shape = "Invalid world shape.";
const char *errmsg_world_char = "Invalid world character.";
const char *errmsg_world_player_missing = "World missing player.";
const char *errmsg_world_player_multiple = "World has multiple players.";

const char *errmsg_direction = "Invalid direction input.";

void Game::input_and_read_world_from_file(const EntityCounter &counter)
{
  string world_file_str;
  // TODO: prompt user for filename
  cout << msg_filename << endl;
  getline(cin, world_file_str);

  // input file stream
  ifstream input_file("world/" + world_file_str + ".txt");
  int expected_width = -1;

  if (!input_file.is_open())
  {
    throw std::runtime_error(errmsg_world_file);
  }
  else
  {
    string line;
    int line_num = 0;
    while (getline(input_file, line))
    {
      // check if each line is the same length to guarantee rectangle world instead of jagged
      if (expected_width == -1)
      {
        expected_width = line.size();
      }
      else if (static_cast<int>(line.size()) != expected_width)
      {
        throw std::runtime_error(errmsg_world_shape);
      }
      // using 1 indexing
      line_num++;
      m_worldRows = line_num;
      for (size_t i = 0; i < line.size(); i++)
      {
        m_worldCols = line.size();
        // if it is not a valid character, throw excpetion
        if (line[i] == 'p')
        {
          // if player vector is too large, throw error
          if (m_player.size() >= 1)
          {
            throw runtime_error(errmsg_world_player_multiple);
          }
          Cell player_cell(line_num, i + 1);
          Player john_conner(player_cell, counter);
          m_player.push_back(john_conner);
        }
        else if (line[i] == 'r')
        {
          Cell robot_cell(line_num, i + 1);
          RobotOrDebris terminator(robot_cell, false, counter);
          m_robotsAndDebris.push_back(terminator);
        }
        else if (line[i] == 'x')
        {
          Cell debris_cell(line_num, i + 1);
          RobotOrDebris debris_pile(debris_cell, true, counter);
          m_robotsAndDebris.push_back(debris_pile);
        }
        else if (line[i] == '.')
        {
          continue;
        }
        else
        {
          throw runtime_error(errmsg_world_char);
        }
      }
    }

    // throw error if the world is empty
    if (expected_width == -1 || expected_width == 0)
    {
      throw runtime_error(errmsg_world_shape);
    }
  }

  if (m_player.size() == 0)
  {
    throw runtime_error(errmsg_world_player_missing);
  }
}

void Game::display_world() const
{
  // start with a grid of characters, then place things on top
  std::vector<std::string> grid(m_worldRows, std::string(m_worldCols, '.'));
  if (!m_player.empty())
  {
    Cell player_cell = m_player.front().get_cell();
    grid[player_cell.row - 1][player_cell.col - 1] = 'p';
  }
  // place robots and debris
  for (const auto &entity : m_robotsAndDebris)
  {
    Cell cell = entity.get_cell();
    if (entity.is_debris())
    {
      grid[cell.row - 1][cell.col - 1] = 'x';
    }
    else
    {
      grid[cell.row - 1][cell.col - 1] = 'r';
    }
  }

  // print the final grid once everything is placed
  for (const auto &row : grid)
  {
    std::cout << row << '\n';
  }
}

GameStatus Game::input_next_move_and_update()
{
  std::string input_line;
  Direction dir;

  cout << msg_direction << endl;
  std::getline(std::cin, input_line);

  if (input_line.empty())
  {
    throw runtime_error(errmsg_direction);
  }

  char dir_char = input_line[0];

  if (dir_char == 'w')
  {
    dir = Direction::north;
  }
  else if (dir_char == 'a')
  {
    dir = Direction::west;
  }
  else if (dir_char == 's')
  {
    dir = Direction::south;
  }
  else if (dir_char == 'd')
  {
    dir = Direction::east;
  }
  else if (dir_char == ' ')
  {
    dir = Direction::none;
  }
  else
  {
    throw runtime_error(errmsg_direction);
  }

  GameStatus status = GameStatus::playing;

  m_player.front().update(dir, m_worldRows, m_worldCols);

  for (size_t i = 0; i < m_robotsAndDebris.size(); i++)
  {
    if (!m_robotsAndDebris.at(i).is_debris())
    {
      m_robotsAndDebris.at(i).update(m_player.front());
    }
  }

  // loop through all the robots and compare their locations to all other robots
  // if the cells are equal, make them both into debris
  for (size_t i = 0; i < m_robotsAndDebris.size(); i++)
  {
    for (size_t j = i + 1; j < m_robotsAndDebris.size(); j++)
    {
      if (m_robotsAndDebris[i].get_cell() == m_robotsAndDebris[j].get_cell())
      {
        m_robotsAndDebris[i].make_debris();
        m_robotsAndDebris[j].make_debris();
      }
    }
  }

  // after making the robots into debris, loop backwards to remove any duplicate debris
  // loop backwards to avoid the problem of removing, then continuing to try to loop through
  // since we are removing only one at a time, index i won't ever be out of range of the vector, we remove one and then it decrements anyway
  for (int i = m_robotsAndDebris.size() - 1; i >= 0; i--)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (m_robotsAndDebris[i].get_cell() == m_robotsAndDebris[j].get_cell() && m_robotsAndDebris[i].is_debris() && m_robotsAndDebris[j].is_debris())
      {
        // once the duplicate debris is found, remove it and we are done
        m_robotsAndDebris.erase(m_robotsAndDebris.begin() + i);
        break;
      }
    }
  }

  // if player and robot/debris cell is the same, player loses
  for (size_t i = 0; i < m_robotsAndDebris.size(); i++)
  {
    if (m_player.front().get_cell() == m_robotsAndDebris.at(i).get_cell())
    {
      status = GameStatus::player_lost;
      m_player.clear();
      break;
    }
  }

  // if the there are no more robots, or if there is just one remaining file of debris, the player wins
  if (status == GameStatus::playing)
  {
    bool has_robot = false;
    for (size_t i = 0; i < m_robotsAndDebris.size(); i++)
    {
      if (!m_robotsAndDebris.at(i).is_debris())
      {
        has_robot = true;
        break;
      }
    }

    if (!has_robot)
    {
      status = GameStatus::player_won;
    }
  }

  return status;
}