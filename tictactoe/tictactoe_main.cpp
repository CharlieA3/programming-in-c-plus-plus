#include "Board.hpp"
#include "GameLogic.hpp"

int main()
{
  Board board;

  game_input_board_size(board);

  while (true) {
    game_display_board_and_input_next_move(board);
  }
}
