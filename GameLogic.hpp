#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "Board.hpp"



// prompts user for board size and reads from stdin.
// sizes outside the range 2-5 or input errors print an error message and the program exits.
void game_input_board_size(Board & board);

// displays the board; if the game is over displays a message about who won and the program exits.
// if the game is ongoing, prompts the appropriate player for input and reads in the row and column of their desired move from stdin.
// if there is any problem with the input (end-of-file; input error; invalid or out of bounds move) the program prints a message and exits.
// otherwise, the game makes the move.
void game_display_board_and_input_next_move(Board & board);



#endif
