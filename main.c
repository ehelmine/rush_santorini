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
	int	*player;
	int *piece;

	player = (int*)malloc(sizeof(int) * 2);
	player[0] = 0;
	player[1] = 0;
	piece = (int*)malloc(sizeof(int) * 2);
	piece[0] = 1;
	piece[1] = 1;
	board = get_board();
	change_player_coordinates_for_board(player);
	change_block_and_dome_coordinates(piece);
	print_board(board, player);
	return (0);
}