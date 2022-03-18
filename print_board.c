#include "santorini.h"
/*
//
// unicorn	"\u1f984" -> "\U0001f984"
// superhero "U+1F9B8" -> "\U0001f9B8"
// mermaid "U+1F9DC" -> "\U0001F9DC"
// monkey "U+1F412" -> "\U0001F412"
// fox "U+1F98A" -> "\U0001F98A"
// panda "U+1F43C" -> "\U0001F43C"
// bee "U+1F41D" -> "\U0001F41D"
// eggplant "U+1F346" -> "\U0001F346"
// peach "U+1F351" -> "\U0001F351"
//*/
void	print_board(char **arr, int players[4][2])
{
	int y = 1;
	int x = 0;
	int i = 0;
	int ii = 0;
	printf("------------------------------------\n");
	while (arr[y] != NULL)
	{
		while (arr[y][x] != '\0')
		{
			i = 0;
			while (i < 4)
			{
				if (players[i][0] == x && players[i][1] == y)
				{
					if (i == 0) // unicorn
					{
						if (arr[y][x] == '1')
							printf(WHITE "\U0001f984" COLOR_RESET);
						else if (arr[y][x] == '2')
							printf(CYAN "\U0001f984" COLOR_RESET);
						else if (arr[y][x] == '3')
							printf(BLUE "\U0001f984" COLOR_RESET);
						else if (arr[y][x] == 'D')
							printf(RED "\U0001f984" COLOR_RESET);
						else
							printf("\U0001f984");
					}
					if (i == 1)  // bee
					{
						if (arr[y][x] == '1')
							printf(WHITE "\U0001F41D" COLOR_RESET);
						else if (arr[y][x] == '2')
							printf(CYAN "\U0001F41D" COLOR_RESET);
						else if (arr[y][x] == '3')
							printf(BLUE "\U0001F41D" COLOR_RESET);
						else if (arr[y][x] == 'D')
							printf(RED "\U0001F41D" COLOR_RESET);
						else
							printf("\U0001F41D");
					}
					if (i == 2)  // eggplant
					{
						if (arr[y][x] == '1')
							printf(WHITE "\U0001F346" COLOR_RESET);
						else if (arr[y][x] == '2')
							printf(CYAN "\U0001F346" COLOR_RESET);
						else if (arr[y][x] == '3')
							printf(BLUE "\U0001F346" COLOR_RESET);
						else if (arr[y][x] == 'D')
							printf(RED "\U0001F346" COLOR_RESET);
						else
							printf("\U0001F346");
					}
					if (i == 3) // peach
					{
						if (arr[y][x] == '1')
							printf(WHITE "\U0001F351" COLOR_RESET);
						else if (arr[y][x] == '2')
							printf(CYAN "\U0001F351" COLOR_RESET);
						else if (arr[y][x] == '3')
							printf(BLUE "\U0001F351" COLOR_RESET);
						else if (arr[y][x] == 'D')
							printf(RED "\U0001F351" COLOR_RESET);
						else
							printf("\U0001F351");
					}
					x += 2;
					break ;
				}
				i++;
			}
			if (arr[y][x] == '1')
				printf(WHITE "%c" COLOR_RESET, ' ');
			else if (arr[y][x] == '2')
				printf(CYAN "%c" COLOR_RESET, ' ');
			else if (arr[y][x] == '3')
				printf(BLUE "%c" COLOR_RESET, ' ');
			else if (arr[y][x] == 'D')
				printf(RED "%c" COLOR_RESET, ' ');
			else
				printf("%c", arr[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
	printf("Lvl1:" WHITE "  " COLOR_RESET "  Lvl2:" CYAN "  " COLOR_RESET "  Lvl3:" BLUE "  " COLOR_RESET "  Dome:" RED "  " COLOR_RESET "\n");
}
