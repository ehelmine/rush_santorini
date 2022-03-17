#include "santorini.h"

void	print_dome(char **arr)
{

}

void	print_one_box(char **arr)
{
	int i = 0;
	int ii = 0;
	while (i < 3)
	{
		while (ii < 7)
		{
			printf("%c", ' ');
			ii++;
		}
		i++;
		ii = 0;
	}
}
//
// unicorn	"\u1f984" -> "\U0001f984"
// superhero "U+1F9B8" -> "\U0001f9B8"
// mermaid "U+1F9DC" -> "\U0001F9DC"
// monkey "U+1F412" -> "\U0001F412"
// fox "U+1F98A" -> "\U0001F98A"
// panda "U+1F43C" -> "\U0001F43C"
// bee "U+1F41D" -> "\U0001F41D"
//
void	print_board(char **arr, int *player)
{
	int start_x[5] = {1, 8, 15, 22, 29};
	int start_y[5] = {1, 5, 9, 13, 17};
	int y = 0;
	int x = 0;
	int i = 0;
	int ii = 0;
	while (arr[y] != NULL)
	{
		while (arr[y][x] != '\0')
		{
			i = 0;
			while (i < 5)
			{
				if (y == start_y[i])
				{
					ii = 0;
					while (ii < 5)
					{
						if (x == start_x[ii])
						{
						//	exit (1);
							print_one_box(arr);
							x += 7;
							i = 5;
							ii = 5;
						}
						ii++;
					}
				}
				i++;
			}
			if (x == player[0])
			{
				if (y == player[1])
				{
					printf(MAGENTA "\U0001f984" COLOR_RESET);
					x++;
				}
				else if (y > 0 && y < 4)
					printf(MAGENTA "%c" COLOR_RESET, arr[y][x]);
				else
					printf("%c", arr[y][x]);
			}
			else if (y > 0 && y < 4)
			{
				if (x > 0 && x < 7)
					printf(MAGENTA "%c" COLOR_RESET, arr[y][x]);
				else
					printf("%c", arr[y][x]);
			}
			else
				printf("%c", arr[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
//	printf("\n");
}
