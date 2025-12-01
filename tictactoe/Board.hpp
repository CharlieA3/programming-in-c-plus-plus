#ifndef BOARD_H
#define BOARD_H

#include "Util.hpp"
#include <vector>
#include <map>

extern const std::map<Space, char> space_to_string_map;

// struct representing the state of the board.
// keeps track of the spaces of the board as well as which player's turn it is.
struct Board
{
  std::vector<std::vector<Space>> spaces; // representation of spaces on the board
  unsigned int size;                      // size of the board
  Space next_move;                        // whose move is next
};

// resets the board to be of the given size; resets to X player's turn.
void board_reset_size(Board &board, unsigned int size);

// makes a move for the current player in the given row and column if possible, and returns true.
// if the move is not possible (the space is already filled or off the board) no move is made and returns false.
// rows and columns are 0-indexed, for example, the coordinates for a 2x2 board would be:
//
// r0 c0 | r0 c1
// -------------
// r1 c0 | r1 c1
bool board_make_move(Board &board, unsigned int row, unsigned int column);

// gets the current status of the game based on the board.
// a game is won by a player if they have filled all the spaces in a row, column, or diagonal.
// a game is tied if it not possible to make any more moves and the game has not been won.
GameStatus board_get_status(const Board &board);

// prints the board to stdout.
// uses X, O and space for spaces and | and - to draw lines.
// for example, a 3x3 board might look like:
//
// X|O|X
// -----
//  | |X
// -----
//  |O|
void board_print(const Board &board);

#endif
