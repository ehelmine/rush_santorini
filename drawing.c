#include "santorini.h"

void	our_error(char *str)
{
	printf("%s\n", str);
	exit (1);
}

char	**get_board(void)
{
	int fd;
	char **board;
	size_t bufsize = 37;
	char buf[38];

	fd = open("board.txt", O_RDONLY);
	if (!fd)
		our_error("open error\n");
	int i = 0;
	board = (char **)malloc(sizeof(char *) * 22);
	if (!board)
		our_error("malloc error\n");
	while (i < 21)
	{
		board[i] = (char *)malloc(sizeof(char) * 38);
		if (!board[i])
			our_error("malloc error\n");
		if (read(fd, buf, 37) == -1)
			our_error("read error\n");
		strcpy(board[i++], buf);
	}
	board[i] = NULL;
	return (board);
}

void	drawing(player_info_t *p1, player_info_t *p2, char **board, int whose_turn_next)
{
	int	players[4][2];

	players[0][0] = p1->w1row;
	players[0][1] = p1->w1col;
	players[1][0] = p1->w2row;
	players[1][1] = p1->w2col;
	players[2][0] = p2->w1row;
	players[2][1] = p2->w1col;
	players[3][0] = p2->w2row;
	players[3][1] = p2->w2col;
	int i = 0;
	while (i < 4)
		change_player_coordinates_for_board(players[i++]);
	printf("%i\n", players[0][0]);
	printf("%i\n", players[0][1]);
	printf("%i\n", players[1][0]);
	printf("%i\n", players[1][1]);
	printf("%i\n", players[2][0]);
	printf("%i\n", players[2][1]);
	printf("%i\n", players[3][0]);
	printf("%i\n", players[3][1]);
/*	n_players = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
		n_players[i++] = (int *)malloc(sizeof(int) * 2);
	n_players[0][0] = players[0][0];
	n_players[0][1] = players[0][1];
	n_players[1][0] = players[1][0];
	n_players[1][1] = players[1][1];
	n_players[2][0] = players[2][0];
	n_players[2][1] = players[2][1];
	n_players[3][0] = players[3][0];
	n_players[3][1] = players[3][1];*/
	print_board(board, players);
//	if (players[3][1] != -1)
//		check_if_player_is_blocked(board, players, whose_turn_next);
/*	i = 0;
	while (i < 4)
	{
		free(n_players[i]);
		n_players[i++] = NULL;
	}
	free(n_players);*/
}