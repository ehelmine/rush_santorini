#include "santorini.h"

void	add_level_letters_to_board(char **board, int *level_coord)
{
	int y = 0;
	int x = 0;
	int orig_y;
	int orig_x;
	char c;
	char level;

	while (board[y] != NULL)
	{
		while (board[y][x] != '\0')
		{
			if (x == level_coord[0] && y == level_coord[1])
			{
				orig_y = y;
				orig_x = x;
				while (y < orig_y + 3)
				{
					c = board[y][x];
					if (c == ' ')
						level = '1';
					else if (c == '1')
						level = '2';
					else if (c == '2')
						level = '3';
					else if (c == '3')
						level = 'D';
					while (x < orig_x + 6)
						board[y][x++] = level;
					y++;
					x = orig_x;
				}
				return ;
				y = orig_y;
				x = orig_x + 8;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	change_block_coordinates(int *block_coord)
{
	block_coord[0] = block_coord[0] + 1 + (block_coord[0] * 6);
	block_coord[1] = block_coord[1] + 1 + (block_coord[1] * 3);
}

void	change_player_coordinates_for_board(int *player)
{
	if (player[0] == -1)
		return ;
	player[0] = player[0] + 3 + (player[0] * 6);
	player[1] = player[1] + ((player[1] + 1) * 3) - 1;
}
