#include "santorini.h"

void	check_if_player_is_blocked(char **board, int players[4][2])
{
	int y = 0;
	int x = 0;
	int p_y = 0;
	int p_x = 0;
	int winner = 0;
	int loser = 0;
	char level;
	level = 0;
	while (y < 4)
	{
		p_y = players[y][1];
		p_x = players[y][0];
		level = board[p_y][p_x];
		if ((p_y - 4 > 1 && p_x - 7 > 1 && board[p_y - 4][p_x - 7] != ' ')
			&& (p_y - 4 > 1 && p_x > 1 && board[p_y - 4][p_x] != ' ') && 
			(p_y - 4 > 1 && p_x + 7 < 34 && board[p_y - 4][p_x + 7] != ' ') &&
			(p_y > 1 && p_x - 7 > 1 && board[p_y][p_x - 7] != ' ') && 
			(p_y > 1 && p_x + 7 < 34 && board[p_y][p_x + 7] != ' ') &&
			(p_y + 4 < 19 && p_x - 7 > 1 && board[p_y + 4][p_x - 7] != ' ') && 
			(p_y + 4 < 19 && p_x + 7 < 34 && board[p_y + 4][p_x + 7] != ' ') &&
			(p_y + 4 < 19 && p_x + 7 < 34 && board[p_y + 4][p_x + 7] != ' '))
		{
			if ((p_y - 4 > 1 && p_x - 7 > 1 && board[p_y - 4][p_x - 7] != '1')
			&& (p_y - 4 > 1 && p_x > 1 && board[p_y - 4][p_x] != '1') && 
			(p_y - 4 > 1 && p_x + 7 < 34 && board[p_y - 4][p_x + 7] != '1') &&
			(p_y > 1 && p_x - 7 > 1 && board[p_y][p_x - 7] != '1') && 
			(p_y > 1 && p_x + 7 < 34 && board[p_y][p_x + 7] != '1') &&
			(p_y + 4 < 19 && p_x - 7 > 1 && board[p_y + 4][p_x - 7] != '1') && 
			(p_y + 4 < 19 && p_x + 7 < 34 && board[p_y + 4][p_x + 7] != '1') &&
			(p_y + 4 < 19 && p_x + 7 < 34 && board[p_y + 4][p_x + 7] != '1'))
			{
				winner = 2;
				loser = 1;
				if (y == 0 || y == 1)
				{
					winner = 1;
					loser = 2;
				}
				printf("No moves left for player %i. Player number %i has won. Congrats!!\n", loser, winner);
				exit (0);
			}
		}
		y++;
	}
}