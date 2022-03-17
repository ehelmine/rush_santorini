#ifndef SHELL_H
# define SHELL_H
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define WHITE	 "\x1b[47m"
#define MAGENTA	"\x1b[46m"
#define COLOR_RESET	"\x1b[0m"

void	change_player_coordinates_for_board(int *player);
void	print_board(char **arr, int *player);

#endif