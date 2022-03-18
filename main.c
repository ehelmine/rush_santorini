#include "santorini.h"

void	compare_block_to_players(player_info_t *player, player_info_t *another, int *block)
{
	if (player->w1col == block[0] && player->w1row == block[1])
	{
		printf("Don't try to build under player.\n");
		exit (1);
	}
	if (player->w2col == block[0] && player->w2row == block[1])
	{
		printf("Don't try to build under player.\n");
		exit (1);
	}
	if (another->w1col == block[0] && another->w1row == block[1])
	{
		printf("Don't try to build under player.\n");
		exit (1);
	}
	if (another->w2col == block[0] && another->w2row == block[1])
	{
		printf("Don't try to build under player.\n");
		exit (1);
	}
}

void	compare_players(player_info_t *player, player_info_t *another)
{
	if (player->w1col == player->w2col && player->w1row == player->w2row)
	{
		printf("Don't put players in the same place.\n");
		exit (1);
	}
	if (another->w1col == another->w2col && another->w1row == another->w2row)
	{
		printf("Don't put players in the same place.\n");
		exit (1);
	}
	if (player->w1col == another->w2col && player->w1row == another->w2row)
	{
		printf("Don't put players in the same place.\n");
		exit (1);
	}
	if (another->w1col == player->w2col && another->w1row == player->w2row)
	{
		printf("Don't put players in the same place.\n");
		exit (1);
	}
}

int isdirection(char *str)
{
	str[0] = toupper(str[0]);
	str[1] = toupper(str[1]);

	char *dirs[] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
	for (int i = 0; i < 8; i++)
	{
		if (!strcmp(dirs[i], str))
			return (i);
	}
	return (-1);
}

int isfree_coord(player_info_t *player, int row, int col, int **board)
{
	int p = player->player + 5;
	if (board[row][col] == 0)
	{

		board[row][col] = p;
		return (1);
	}
	printf("Cell occupied\n");
	return (0);
}

int get_input(int min, int max)
{
	int nbr;
	char *buffer;
	size_t bufsize = 1;

	do {
		buffer = (char *)malloc(bufsize * sizeof(char));
		getline(&buffer, &bufsize, stdin);
		if ((atoi(buffer) > max || atoi(buffer) < min))
			printf("Choose input between (%d - %d)\n", min, max);
	} while((atoi(buffer) > max || atoi(buffer) < min));

	nbr = atoi(buffer);
	free(buffer);
	if (nbr >= min && nbr <= max)
		return nbr - 1;
	return (-1);
}

int isstring(char *str)
{
	while (*str)
	{
		if (!isalpha(*str))
			return (0);
	}
	return (1);
}

int    *is_valid_move(int dir, player_info_t *player, int worker)
{
	int offsets[8][2] = {
	{0, -1},
	{1, -1},
	{ 1, 0},
	{ 1, 1},
	{ 0, 1},
	{ -1, 1},
	{ -1, 0},
	{-1,-1}};
	int wrow;
	int wcol;
	if (worker == 1)
	{
		wrow = player->w1row;
		wcol = player->w1col;
	}
	else if (worker == 2)
	{
		wrow = player->w2row;
		wcol = player->w2col;
	}
	int *target;
	target = (int *)malloc(sizeof(int) * 2);
	target[0] = offsets[dir][0] + wcol;
	target[1] = offsets[dir][1] + wrow;	
	if (target[0] < 0 || target[0] > 4 || target[1] < 0 || target[1] > 4)
		return (NULL);
	return (target);
}

int get_command(player_info_t *player, char **new_board, player_info_t *another, int who)
{
	int worker;
	char *buffer;
	size_t bufsize;
	int mvdir;
	int bdir;
	int *block;

	buffer = NULL;
	printf("Choose worker: ");
	worker = get_input(1, 2) + 1;
	printf("\nChoose direction to move: ");

	move:
		do {
			getline(&buffer, &bufsize, stdin);
			if (strlen(buffer) == 2)
				buffer[1] = '\0';
			else
				buffer[2] = '\0';
			mvdir = isdirection(buffer);
			if (mvdir < 0)
				printf("Invalid direction\n");
		} while(mvdir < 0);
	block = is_valid_move(mvdir, player, worker);
	if (block == NULL)
	{
		printf("Wrong direction. Please start again\n");
		exit (1);
	}
	if (worker == 1)
	{
		player->w1col = block[0];
		player->w1row = block[1];
	}
	else if (worker == 2)
	{
		player->w2col = block[0];
		player->w2row = block[1];
	}
	compare_players(player, another);
	if (who == 1)
		drawing(player, another, new_board, 0);
	else if (who == 2)
		drawing(another, player, new_board, 0);
	printf("\nChoose direction to build: ");
	
	build:
		do {
			getline(&buffer, &bufsize, stdin);
			if (strlen(buffer) == 2)
			    buffer[1] = '\0';
			else
			    buffer[2] = '\0';
			bdir = isdirection(buffer);
			if (bdir < 0)
			    printf("Invalid direction\n");
		} while(bdir < 0);

	block = is_valid_move(bdir, player, worker);
	if (block == NULL)
	{
		printf("Wrong direction. Please start again\n");
		exit (1);
	}
	compare_block_to_players(player, another, block);
	change_block_coordinates(block);
	add_level_letters_to_board(new_board, block);
	return (0);
}

char **init_players(player_info_t *p1, player_info_t *p2, int **board)
{
	int wrow;
	int wcol;
	char **new_board;
	p1->player = 1;
	p2->player = 2;
	printf("Player 1 enter worker starting coordinates\n");
//	return ;
	do {
		printf("Worker 1 starting row: ");
		wcol = get_input(1, 5);
		printf("Worker 1 starting col: ");
		wrow = get_input(1, 5);
	} while(!isfree_coord(p1, wrow, wcol, board));

	p1->w1row = wrow;
	p1->w1col = wcol;
//	print_board(board);
	new_board = get_board();
	drawing(p1, p2, new_board, 0);

	printf("\n");
	do {
		printf("Worker 2 starting row: ");
		wcol = get_input(1, 5);
		printf("Worker 2 starting col: ");
		wrow = get_input(1, 5);
	} while(!isfree_coord(p1, wrow, wcol, board));

	p1->w2row = wrow;
	p1->w2col = wcol;
//	print_board(board);
	drawing(p1, p2, new_board, 0);

	printf("Player 2 enter worker starting coordinates\n");

	do {
		printf("Worker 1 starting row: ");
		wcol = get_input(1, 5);
		printf("Worker 1 starting col: ");
		wrow = get_input(1, 5);
	} while(!isfree_coord(p2, wrow, wcol, board));

	p2->w1row = wrow;
	p2->w1col = wcol;
//	print_board(board);
	drawing(p1, p2, new_board, 0);

	printf("\n");
	do {
		printf("Worker 2 starting row: ");
		wcol = get_input(1, 5);
		printf("Worker 2 starting col: ");
		wrow = get_input(1, 5);
	} while(!isfree_coord(p2, wrow, wcol, board));

	p2->w2row = wrow;
	p2->w2col = wcol;
//	print_board(board);
	drawing(p1, p2, new_board, 0);
	return (new_board);
}

void init_board(int **board)
{
	for (int row = 0; row < 5; row++)
	{
		board[row] = malloc(sizeof(int) * 5);
		for (int col = 0; col < 5; col++)
		{
			board[row][col] = 0;
		}
	}
}

int main(void)
{
	int whose_turn_next = 1;
	int temp;
	int **board = (int **)malloc(sizeof(int) * 7);
	player_info_t *p1 = (player_info_t *)malloc(sizeof(player_info_t));
	player_info_t *p2 = (player_info_t *)malloc(sizeof(player_info_t));

	init_board(board);
	p1->w1col = -1;
	p1->w1row = -1;
	p1->w2row = -1;
	p1->w2col = -1;
	p2->w1row = -1;
	p2->w1col = -1;
	p2->w2row = -1;
	p2->w2col = -1;
	char **new_board;
	new_board = init_players(p1, p2, board);
	while (1)
	{
		get_command(p1, new_board, p2, 1);
		drawing(p1, p2, new_board, 2);
		get_command(p2, new_board, p1, 2);
		drawing(p1, p2, new_board, 1);
	}

	// free(p1);
	// free(p2);
	// free(board);
	return (0);
}