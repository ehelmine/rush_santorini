#include "santorini.h"

void	print_dome(char **arr)
{

}

void	print_player(char **arr)
{

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
	int y = 0;
	int x = 0;
	int i = 0;
	while (arr[y] != NULL)
	{
		while (arr[y][x] != '\0')
		{
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
