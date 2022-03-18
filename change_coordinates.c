#include "santorini.h"

void	add_block_letters_to_board(char **board, int *block, char level)
{
	int y = 0;
	int x = 0;
	int orig_y;
	int orig_x;

	while (board[y] != NULL)
	{
		while (board[y][x] != '\0')
		{
			if (x == block[0] && y == block[1])
			{
				orig_y = y;
				orig_x = x;
				while (y < orig_y + 3)
				{
					while (x < orig_x + 6)
						board[y][x++] = level;
					y++;
					x = orig_x;
				}
				y = orig_y;
				x = orig_x + 8;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	add_dome_letters_to_board(char **board, int *dome)
{
	int y = 0;
	int x = 0;
	int orig_y;
	int orig_x;

	while (board[y] != NULL)
	{
		while (board[y][x] != '\0')
		{
			if (x == dome[0] && y == dome[1])
			{
				orig_y = y;
				orig_x = x;
				while (y < orig_y + 3)
				{
					while (x < orig_x + 6)
						board[y][x++] = 'D';
					y++;
					x = orig_x;
				}
				y = orig_y;
				x = orig_x + 8;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	change_block_and_dome_coordinates(int *piece)
{
	piece[0] = piece[0] + 1 + (piece[0] * 6);
	piece[1] = piece[1] + 1 + (piece[1] * 3);
	printf("piece x %i piece y %i\n", piece[0], piece[1]);
}

void	change_player_coordinates_for_board(int *player)
{
	if (player[0] == -1)
		return ;
	player[0] = player[0] + 3 + (player[0] * 6);
	player[1] = player[1] + ((player[1] + 1) * 3) - 1;
//	printf("player x %i player y %i\n", player[0], player[1]);
}
