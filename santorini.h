#ifndef SANTORINI_H
# define SANTORINI_H
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#define WHITE		"\x1b[47m"
#define CYAN		"\x1b[46m"
#define MAGENTA 	"\x1b[45m"
#define BLUE		"\x1b[44m"
#define YELLOW		"\x1b[43m"
#define GREEN		"\x1b[42m"
#define RED			"\x1b[41m"
#define BLACK		"\x1b[40m"
#define COLOR_RESET	"\x1b[0m"

typedef struct
{
	int player;
	int w1row;
	int w1col;
	int w2row;
	int w2col;
} player_info_t;

char	**get_board(void);
void	drawing(player_info_t *p1, player_info_t *p2, char **board);
void	change_player_coordinates_for_board(int *player);
void	change_block_coordinates(int *piece);
void	add_level_letters_to_board(char **board, int *level_coord, char level);
void	print_board(char **board, int players[4][2]);
void	check_if_player_is_blocked(char **board, int players[4][2]);

#endif