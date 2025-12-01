#include "Board.hpp"

#include <iostream>
using namespace std;

const map<Space, char> space_to_string_map = {
    {Space::X, 'X'},
    {Space::O, 'O'},
    {Space::BLANK, ' '}};

void board_reset_size(Board &board, unsigned int size)
{
  board.size = size;
  board.spaces.resize(size);
  for (size_t i = 0; i < size; i++)
  {
    board.spaces[i].resize(size);
    for (size_t j = 0; j < size; j++)
    {
      board.spaces[i][j] = Space::BLANK;
    }
  }
  board.next_move = Space::X;
}

bool board_make_move(Board &board, unsigned int row, unsigned int column)
{
  if (static_cast<int>(row) > -1 && row<board.size &&static_cast<int>(column)> - 1 && column < board.size)
  {
    if (board.spaces[row][column] == Space::BLANK)
    {
      board.spaces[row][column] = board.next_move;
      // Switch turns
      if (board.next_move == Space::X)
        board.next_move = Space::O;
      else
        board.next_move = Space::X;
      return true;
    }
  }
  return false;
}

GameStatus board_get_status(const Board &board)
{
  size_t board_size = board.size;
  bool has_blank_space = false;

  // checking rows and columns
  for (size_t i = 0; i < board_size; ++i)
  {
    // row i
    if (board.spaces[i][0] != Space::BLANK)
    {
      bool same_row = true;
      for (size_t j = 1; j < board_size; ++j)
      {
        if (board.spaces[i][j] != board.spaces[i][0])
        {
          same_row = false;
          break;
        }
      }
      if (same_row)
        return (board.spaces[i][0] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
    }

    // column i
    if (board.spaces[0][i] != Space::BLANK)
    {
      bool same_col = true;
      for (size_t j = 1; j < board_size; ++j)
      {
        if (board.spaces[j][i] != board.spaces[0][i])
        {
          same_col = false;
          break;
        }
      }
      if (same_col)
        return (board.spaces[0][i] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
    }
  }

  // diagonal from top left to bottom right
  if (board.spaces[0][0] != Space::BLANK)
  {
    bool same_diag1 = true;
    for (size_t i = 1; i < board_size; ++i)
    {
      if (board.spaces[i][i] != board.spaces[0][0])
      {
        same_diag1 = false;
        break;
      }
    }
    if (same_diag1)
      return (board.spaces[0][0] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
  }

  // diagonal from top right to bottom left
  if (board.spaces[0][board_size - 1] != Space::BLANK)
  {
    bool same_diag2 = true;
    for (size_t i = 1; i < board_size; ++i)
    {
      if (board.spaces[i][board_size - 1 - i] != board.spaces[0][board_size - 1])
      {
        same_diag2 = false;
        break;
      }
    }
    if (same_diag2)
      return (board.spaces[0][board_size - 1] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
  }

  // determining tie
  int x_count = 0;
  int o_count = 0;

  for (size_t i = 0; i < board_size; ++i)
  {
    for (size_t j = 0; j < board_size; ++j)
    {
      if (board.spaces[i][j] == Space::X)
        ++x_count;
      else if (board.spaces[i][j] == Space::O)
        ++o_count;
      else
        has_blank_space = true;
    }
  }

  if (!has_blank_space)
    return GameStatus::OVER_TIE;

  return (x_count <= o_count) ? GameStatus::PLAYING_X_TURN : GameStatus::PLAYING_O_TURN;
}

void board_print(const Board &board)
{
  for (size_t i = 0; i < board.size; i++)
  {
    for (size_t j = 0; j < board.size; j++)
    {
      cout << space_to_string_map.at(board.spaces[i][j]);
      if (j < board.size - 1)
        cout << "|";
    }
    cout << endl;
    if (i < board.size - 1)
    {
      for (size_t j = 0; j < board.size; j++)
      {
        cout << "-";
        if (j < board.size - 1)
          cout << "-";
      }
      cout << endl;
    }
  }
}