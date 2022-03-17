#include "santorini.h"

void	change_player_coordinates_for_board(int *player)
{
	player[0] = player[0] + 3 + (player[0] * 6);
	player[1] = player[1] + ((player[1] + 1) * 3) - 1;
//	printf("x %i y %i\n", player[0], player[1]);
}
