#include <stdlib.h>
#include <stdio.h>
#include "minesweeper-utils.h"

typedef struct Guess
{
	unsigned short int column;
	unsigned short int row;
} Guess;

void test(
	unsigned short int width,
	unsigned short int height,
	float probability,
	const Guess* guess
)
{
	srand(3);
	Map* map = create_map(width, height);
	if (!map)
	{
		return;
	}
	initialize_map(map, probability);
	print_map(map);
	bool lost = false;
	while (!all_empty_tiles_visible(map))
	{
		lost = is_bomb_tile(map, guess->column, guess->row);
		print_map(map);
		if (lost)
		{
			printf("You lost!\n");
			break;
		}
		++guess;
	}
	if (!lost)
	{
		printf("You won!\n");
	}
	destroy_map(map);
}

int main(void)
{
	{
		printf("Testcase 0\n");
		const Guess guesses[] = {
			{0, 0},
			{2, 2},
			{1, 1}
		};
		test(2, 2, 0.5f, guesses);
	}

	{
		printf("Testcase 1\n");
		const Guess guesses[] = {
			{0, 8},
			{0, 0},
			{0, 2},
			{0, 7},
			{0, 4},
			{0, 3},
			{0, 1},
			{0, 6},
			{0, 5}
		};
		test(1, 9, 0.7582f, guesses);
	}

	{
		printf("Testcase 2\n");
		const Guess guesses[] = {
			{0, 0},
			{0, 1}
		};
		test(2, 2, 0.5f, guesses);
	}

	{
		printf("Testcase 3\n");
		const Guess guesses[] = {
			{0, 0},
			{1, 2},
			{0, 2},
			{1, 1}
		};
		test(2, 3, 0.6f, guesses);
	}

	{
		printf("Testcase 4\n");
		const Guess guesses[] = {
			{0, 0},
			{2, 0},
			{2, 1},
			{1, 1}
		};
		test(3, 2, 0.5f, guesses);
	}
}
