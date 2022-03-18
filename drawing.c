#include "santorini.h"

void	check_if_someone_won(char **board, int players[4][2])
{
	int y =0;
	int x = 0;
	int i = 0;
	while (board[y] != NULL)
	{
		while (board[y][x] != '\0')
		{
			if (board[y][x] == '3')
			{
				i = 0;
				while (i < 4)
				{
					if (players[i][0] == x && players[i][1] == y)
					{
						printf("Congrats! Somebody won!\n");
						exit (0);
					}
					i++;
				}
			}
			x++;
		}
		y++;
		x = 0;
	}
}

char	**get_board(void)
{
	char **board;
	board = (char **)malloc(sizeof(char *) * 22);
	board[0] = strdup("------------------------------------\n");
	board[1] = strdup("|      |      |      |      |      |\n");
	board[2] = strdup("|      |      |      |      |      |\n");
	board[3] = strdup("|      |      |      |      |      |\n");
	board[4] = strdup("|------|------|------|------|------|\n");
	board[5] = strdup("|      |      |      |      |      |\n");
	board[6] = strdup("|      |      |      |      |      |\n");
	board[7] = strdup("|      |      |      |      |      |\n");
	board[8] = strdup("|------|------|------|------|------|\n");
	board[9] = strdup("|      |      |      |      |      |\n");
	board[10] = strdup("|      |      |      |      |      |\n");
	board[11] = strdup("|      |      |      |      |      |\n");
	board[12] = strdup("|------|------|------|------|------|\n");
	board[13] = strdup("|      |      |      |      |      |\n");
	board[14] = strdup("|      |      |      |      |      |\n");
	board[15] = strdup("|      |      |      |      |      |\n");
	board[16] = strdup("|------|------|------|------|------|\n");
	board[17] = strdup("|      |      |      |      |      |\n");
	board[18] = strdup("|      |      |      |      |      |\n");
	board[19] = strdup("|      |      |      |      |      |\n");
	board[20] = strdup("------------------------------------\n");
	board[21] = NULL;
	return (board);
}

void	drawing(player_info_t *p1, player_info_t *p2, char **board, int whose_turn_next)
{
	int	players[4][2];

	players[0][0] = p1->w1col;
	players[0][1] = p1->w1row;
	players[1][0] = p1->w2col;
	players[1][1] = p1->w2row;
	players[2][0] = p2->w1col;
	players[2][1] = p2->w1row;
	players[3][0] = p2->w2col;
	players[3][1] = p2->w2row;
	int i = 0;
	while (i < 4)
		change_player_coordinates_for_board(players[i++]);
	print_board(board, players);
	if (players[3][1] != 1)
		check_if_someone_won(board, players);
	if (players[3][1] != -1)
		check_if_player_is_blocked(board, players, whose_turn_next);
}