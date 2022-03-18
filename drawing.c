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
	board = (char **)malloc(sizeof(char *) * 23);
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

void	drawing(player_info_t *p1, player_info_t *p2, char **board)
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
//	change_block_and_dome_coordinates(piece);
//	change_block_and_dome_coordinates(block);
//	add_dome_letters_to_board(board, piece);
//	add_block_letters_to_board(board, block, '2');
	print_board(board, players);
	if (players[3][1] != -1)
		check_if_player_is_blocked(board, players);
}