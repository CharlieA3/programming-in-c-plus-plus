#include "GameLogic.hpp"

#include "Board.hpp"
#include "Util.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

const string PROMPT_BOARD_SIZE = "Input board size (2-5):";
const string PROMPT_MOVE_X = "Enter row and column for X:";
const string PROMPT_MOVE_O = "Enter row and column for O:";
const string PROMPT_TIE = "Tie game!";
const string PROMPT_WIN_X = "X wins!";
const string PROMPT_WIN_O = "O wins!";
const string MESSAGE_ERROR = "Invalid input.";

void success_exit()
{
  exit(0);
}

void error_exit()
{
  cout << MESSAGE_ERROR << endl;
  exit(-1);
}

void game_input_board_size(Board &board)
{
  int board_size = 0;
  cout << PROMPT_BOARD_SIZE << endl;

  if (!(cin >> board_size))
  {
    error_exit();
  }

  if (board_size >= 2 && board_size <= 5)
  {
    board_reset_size(board, board_size);
    board_print(board);
  }
  else
  {
    error_exit();
  }
}

void game_display_board_and_input_next_move(Board &board)
{
  GameStatus status = board_get_status(board);
  switch (status)
  {
  case (GameStatus::PLAYING_X_TURN):
    cout << PROMPT_MOVE_X << endl;
    break;
  case (GameStatus::PLAYING_O_TURN):
    cout << PROMPT_MOVE_O << endl;
    break;
  case (GameStatus::OVER_TIE):
    cout << PROMPT_TIE << endl;
    success_exit();
    break;
  case (GameStatus::OVER_X_WON):
    cout << PROMPT_WIN_X << endl;
    success_exit();
    break;
  case (GameStatus::OVER_O_WON):
    cout << PROMPT_WIN_O << endl;
    success_exit();
    break;
  }

  unsigned int row, column;
  if (!(cin >> row >> column))
  {
    error_exit();
  }

  bool move_made = board_make_move(board, row, column);

  if (!move_made)
  {
    error_exit();
  }

  board_print(board);
}