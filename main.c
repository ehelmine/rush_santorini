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

int	main(void)
{
	char **board;
	int	**players;
	int *piece;
	int	*block;

	players = (int**)malloc(sizeof(int*) * 4);
	players[0] = (int*)malloc(sizeof(int) * 2);
	players[0][0] = 1;
	players[0][1] = 2;
	players[1] = (int*)malloc(sizeof(int) * 2);
	players[1][0] = 1;
	players[1][1] = 1;
	players[2] = (int*)malloc(sizeof(int) * 2);
	players[2][0] = 0;
	players[2][1] = 0;
	players[3] = (int*)malloc(sizeof(int) * 2);
	players[3][0] = 4;
	players[3][1] = 2;
	piece = (int*)malloc(sizeof(int) * 2);
	piece[0] = 1;
	piece[1] = 1;
	block = (int*)malloc(sizeof(int) * 2);
	block[0] = 1;
	block[1] = 2;
	board = get_board();
	int i = 0;
	while (i < 4)
		change_player_coordinates_for_board(players[i++]);
	change_block_and_dome_coordinates(piece);
	change_block_and_dome_coordinates(block);
	add_dome_letters_to_board(board, piece);
	add_block_letters_to_board(board, block, '2');
	print_board(board, players, piece, block);
	return (0);
}