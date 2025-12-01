#ifndef UTIL_H
#define UTIL_H

// enum representing what is in a space on the board
enum class Space
{
  X,    // space is occupied by X player
  O,    // space is occupied by O player
  BLANK // space is blank
};

// enum representing the current status of the game
enum class GameStatus
{
  PLAYING_X_TURN, // game is ongoing and it's X player's turn
  PLAYING_O_TURN, // game is ongoing and it's O player's turn
  OVER_TIE,       // game is over and ended in a tie
  OVER_X_WON,     // game is over and X player won
  OVER_O_WON      // game is over and O player won
};

#endif
