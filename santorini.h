#ifndef SANTORINI_H
# define SANTORINI_H
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define WHITE		"\x1b[47m"
#define CYAN		"\x1b[46m"
#define MAGENTA 	"\x1b[45m"
#define BLUE		"\x1b[44m"
#define YELLOW		"\x1b[43m"
#define GREEN		"\x1b[42m"
#define RED			"\x1b[41m"
#define BLACK		"\x1b[40m"
#define COLOR_RESET	"\x1b[0m"

void	change_player_coordinates_for_board(int *player);
void	change_block_and_dome_coordinates(int *piece);
void	add_dome_letters_to_board(char **board, int *dome);
void	add_block_letters_to_board(char **board, int *block, char level);
void	print_board(char **arr, int **players);

#endif