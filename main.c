#include "santorini.h"
/*
void print_board(int **board)
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			if (board[row][col] == 6)
				printf("%s\t", "A");
			else if (board[row][col] == 7)
				printf("%s\t", "X");
			else
				printf("%d\t", board[row][col]);
		}
		printf("\n");
	}
}*/

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

int get_command()
{
	int worker;
	char *buffer;
    size_t bufsize = 2;

	printf("Choose worker: ");
    worker = get_input(1, 2) + 1;
	printf("\nChoose direction to move: ");

    // do {
        buffer = (char *)malloc(bufsize * sizeof(char));
        getline(&buffer, &bufsize, stdin);
		buffer[2] = '\0';
		printf("%s", buffer);
		printf("%lu", strlen(buffer));
		if (strlen(buffer) != 3 && !isstring(buffer))
			printf("Invalid direction");
	// } while(strlen(buffer) != 3 && !isstring(buffer));
	return (worker);
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
		wrow = get_input(1, 5);
		printf("Worker 1 starting col: ");
		wcol = get_input(1, 5);
	} while(!isfree_coord(p1, wrow, wcol, board));

	p1->w1row = wrow;
	p1->w1col = wcol;
//	print_board(board);
	new_board = get_board();
	drawing(p1, p2, new_board, 0);

	printf("\n");
	do {
		printf("Worker 2 starting row: ");
		wrow = get_input(1, 5);
		printf("Worker 2 starting col: ");
		wcol = get_input(1, 5);
	} while(!isfree_coord(p1, wrow, wcol, board));

	p1->w2row = wrow;
	p1->w2col = wcol;
//	print_board(board);
	drawing(p1, p2, new_board, 0);

	printf("Player 2 enter worker starting coordinates\n");

	do {
		printf("Worker 1 starting row: ");
		wrow = get_input(1, 5);
		printf("Worker 1 starting col: ");
		wcol = get_input(1, 5);
	} while(!isfree_coord(p2, wrow, wcol, board));

	p2->w1row = wrow;
	p2->w1col = wcol;
//	print_board(board);
	drawing(p1, p2, new_board, 0);

	printf("\n");
	do {
		printf("Worker 2 starting row: ");
		wrow = get_input(1, 5);
		printf("Worker 2 starting col: ");
		wcol = get_input(1, 5);
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
	int **board = (int **)malloc(sizeof(int) * 7);
	player_info_t *p1 = (player_info_t *)malloc(sizeof(player_info_t));
	player_info_t *p2 = (player_info_t *)malloc(sizeof(player_info_t));

	init_board(board);
	p1->w2row = -1;
	p1->w2col = -1;
	p2->w1row = -1;
	p2->w1col = -1;
	p2->w2row = -1;
	p2->w2col = -1;
	char **new_board = init_players(p1, p2, board);
	while (1)
	{
		get_command();
	//	change_block_coordinates(block); <- lahetetaan tanne sen rakennettavan asian koordinaatit
	//										jotka on saatu inputtina (lahetysformaattia voi
	//										muuttaa, nyt se on int *)
	//	add_level_letters_to_board(new_board, block, level); <- taalla muokataan char **new_boardia
	//													esim jos laitetaan ruutuun 1,1
	//													level2:n taso -> taytetaan 1,1 ruutu
	//													charilla 2
		drawing(p1, p2, new_board, whose_turn_next); // <- ja taalla piirretaan
	}

	// free(p1);
	// free(p2);
	// free(board);
	return (0);
}