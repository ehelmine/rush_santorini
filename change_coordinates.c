#include "santorini.h"

void	change_block_and_dome_coordinates(int *piece)
{
	piece[0] = piece[0] + 1 + (piece[0] * 6);
	piece[1] = piece[1] + 1 + (piece[1] * 3);
	printf("x %i y %i\n", piece[0], piece[1]);
}

void	change_player_coordinates_for_board(int *player)
{
//	player[0] = player[0] + 3 + (player[0] * 6);
//	player[1] = player[1] + ((player[1] + 1) * 3) - 1;
	player[0] = player[0] + 4 + (player[0] * 6);
	player[1] = player[1] + ((player[1] + 1) * 3);
	printf("player x %i player y %i\n", player[0], player[1]);
}
