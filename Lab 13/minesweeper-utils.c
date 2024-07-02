#include "minesweeper-utils.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char state;
	bool is_visible;
} Tile;

typedef Tile* Row;

typedef struct Map{
	unsigned short int width;
	unsigned short int height;
	Row* grid;
} Map;


Map* create_map(unsigned short int width, unsigned short int height)
{
	Map* map = (Map*)calloc(1,sizeof(Map));
	if (!map) {
		return NULL;
	}

	map->width = width;
	map->height = height;
	map->grid = (Row*)calloc(height , sizeof(Row));
	if (!map->grid) {
		free(map);
		return NULL;
	}

	for (unsigned short int i = 0; i < height; ++i) {
		map->grid[i] = (Tile*)calloc(width , sizeof(Tile));
		if (!map->grid[i]) {
			for (unsigned short int j = 0; j < i; ++j) {
				free(map->grid[j]);
			}
			free(map->grid);
			free(map);
			return NULL;
		}

		// �� Tile �ʱ�ȭ
		for (unsigned short int j = 0; j < width; ++j) {
			map->grid[i][j].state = ' ';
			map->grid[i][j].is_visible = false;
		}
	}

	return map;
}

void destroy_map(Map* map)
{
	if (map == NULL) {
		return;
	}

	for (int i = 0; i < map->height; i++)
	{
		free(map->grid[i]);
	}
	free(map->grid);

	free(map);
}

void set_tile(Map* map, unsigned short int column, unsigned short int row, char state, bool is_visible) {
	// ��ȿ�� ��ǥ���� Ȯ��
	if (row >= map->height || column >= map->width) {
		return; // ��ȿ���� ���� ��ǥ�� ��� �Լ� ����
	}

	// ������ ��ǥ�� Ÿ�� ����
	map->grid[row][column].state = state;
	map->grid[row][column].is_visible = is_visible;
}

void initialize_map(Map* map, float probability)
{
	int mine_counter = 0;
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			map->grid[i][j].is_visible = false;
			float r = (float)(rand() % 100);
			if (r >= probability * 100)
			{
				map->grid[i][j].state = 'X';
			}
		}
	}
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j].state != 'X')
			{
				for (int x = j - 1; x <= j + 1; x++) {
					for (int y = i - 1; y <= i + 1; y++) {
						if (y < 0 || x < 0 || y >= map->height || x >= map->width)
							continue;
						else if (map->grid[y][x].state == 'X')
							mine_counter += 1;
					}
				}
				map->grid[i][j].state = (char)(mine_counter + '0');
				mine_counter = 0;
			}
		}
	}
}

void print_map(const Map* map) {
	// ���� NULL���� Ȯ��
	if (map == NULL) {
		return;
	}

	putchar(' ');
	// ���� Ÿ���� �� ������ ���
	for (int i = 0; i < map->width; i++) {
		putchar(' ');
		putchar(i + '0');
	}
	putchar('\n');
	for (unsigned short int i = 0; i < map->height; ++i) {
		putchar(i + '0');
		for (unsigned short int j = 0; j < map->width; ++j) {
			putchar('|');
			if (map->grid[i][j].is_visible) {
				// Ÿ���� ���̸� ���¸� ���
				putchar(map->grid[i][j].state);
			}
			else {
				// Ÿ���� ������ ������ ������ ���
				putchar(' ');
			}
		}
		// ���� ������ �ٹٲ� ���� �߰�
		putchar('|');
		putchar('\n');
	}
}

void reveal_all_tiles(Map* map)
{
	for(int i = 0; i < map->height; i++)
		for (int j = 0; j < map->width; j++)
			map->grid[i][j].is_visible = true;
}

bool all_empty_tiles_visible(const Map* map)
{
	int count_empty = 0;
	int count_empty_visible = 0;

	for (int i = 0; i < map->height; ++i)
	{
		for (int j = 0; j < map->width; ++j)
		{
			if (map->grid[i][j].state != 'X')
			{
				count_empty++;

				if (map->grid[i][j].is_visible)
				{
					count_empty_visible++;
				}
			}
		}
	}

	// Check if all empty tiles are visible
	return count_empty == count_empty_visible;
}



bool is_bomb_tile(Map* map, unsigned short int column, unsigned short int row)
{
	if (row >= map->height || column >= map->width)
	{
		printf("Error: wrong column or row specified.\n");
		return false;
	}
	map->grid[row][column].is_visible = true;
	if (map->grid[row][column].state == 'X')
		return true;
	else
		return false;
}
