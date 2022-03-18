#include "santorini.h"

void	check_if_player_is_blocked(char **board, int players[4][2], int whose_turn_next)
{
	int i = 0;
	int ii = 0;
	int p_y = 0;
	int p_x = 0;
	int winner = 0;
	int loser = 0;
	char level = 0;
	int y = 0;
	int x = 4;
	if (whose_turn_next == 1)
		x = 2;
	else if (whose_turn_next == 2)
		y = 2;
	while (y < x)
	{
		p_y = players[y][1];
		p_x = players[y][0];
		level = board[p_y][p_x];
		if (level == ' ')
			level = 0;
		if (level == 'D')
			level = 4;
		ii = 0;
		if (x == 2)
			ii = 2;
		if (p_y - 4 > 1 && p_x - 7 > 1)
		{
			if ((p_x - 7 != players[ii][0] && p_y - 4 != players[ii][1]) ||
				(p_x - 7 != players[ii + 1][0] && p_y - 4 != players[ii + 1][1]))
			{
				if (board[p_y - 4][p_x - 7] == ' ')
					return ;
				if (board[p_y - 4][p_x - 7] < level + 1 || board[p_y - 4][p_x - 7] == 3)
					return ;
			}
		}
		if (p_y - 4 > 1 && p_x > 1)
		{
			if ((p_x != players[ii][0] && p_y - 4 != players[ii][1]) ||
				(p_x != players[ii + 1][0] && p_y - 4 != players[ii + 1][1]))
			{
				if (board[p_y - 4][p_x] == ' ')
					return ;
				if (board[p_y - 4][p_x] < level + 1 || board[p_y - 4][p_x] == 3)
					return ;
			}
		}
		if (p_y - 4 > 1 && p_x + 7 < 34)
		{
			if ((p_x + 7 != players[ii][0] && p_y - 4 != players[ii][1]) ||
				(p_x + 7 != players[ii + 1][0] && p_y - 4 != players[ii + 1][1]))
			{
				if (board[p_y - 4][p_x + 7] == ' ')
					return ;
				if (board[p_y - 4][p_x + 7] < level + 1 || board[p_y - 4][p_x + 7] == 3)
					return ;
			}
		}
		if (p_y > 1 && p_x - 7 > 1)
		{
			if ((p_x - 7 != players[ii][0] && p_y != players[ii][1]) ||
				(p_x - 7 != players[ii + 1][0] && p_y != players[ii + 1][1]))
			{
				if (board[p_y][p_x - 7] == ' ')
					return ;
				if (board[p_y][p_x - 7] < level + 1 || board[p_y][p_x - 7] == 3)
					return ;
			}
		}
		if (p_y > 1 && p_x + 7 < 34)
		{
			if ((p_x + 7 != players[ii][0] && p_y != players[ii][1]) ||
				(p_x + 7 != players[ii + 1][0] && p_y != players[ii + 1][1]))
			{
				if (board[p_y][p_x + 7] == ' ')
					return ;
				if (board[p_y][p_x + 7] < level + 1 || board[p_y][p_x + 7] == 3)
					return ;
			}
		}
		if (p_y + 4 < 19 && p_x - 7 > 1)
		{
			if ((p_x - 7 != players[ii][0] && p_y + 4 != players[ii][1]) ||
				(p_x - 7 != players[ii + 1][0] && p_y + 4 != players[ii + 1][1]))
			{
				if (board[p_y + 4][p_x - 7] == ' ')
					return ;
				if (board[p_y + 4][p_x - 7] < level + 1 || board[p_y + 4][p_x - 7] == 3)
					return ;
			}
		}
		if (p_y + 4 < 19 && p_x > 1)
		{
			if ((p_x != players[ii][0] && p_y + 4 != players[ii][1]) ||
				(p_x != players[ii + 1][0] && p_y + 4 != players[ii + 1][1]))
			{
				if (board[p_y + 4][p_x] == ' ')
					return ;
				if (board[p_y + 4][p_x] < level + 1 || board[p_y + 4][p_x] == 3)
					return ;
			}
		}
		if (p_y + 4 < 19 && p_x + 7 > 1)
		{
			if ((p_x + 7 != players[ii][0] && p_y + 4 != players[ii][1]) ||
				(p_x + 7 != players[ii + 1][0] && p_y + 4 != players[ii + 1][1]))
			{
				if (board[p_y + 4][p_x + 7] == ' ')
					return ;
				if (board[p_y + 4][p_x + 7] < level + 1 || board[p_y + 4][p_x + 7] == 3)
					return ;
			}
		}
		y++;
	}
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