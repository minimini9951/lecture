#ifndef Q_H
#define Q_H

#include <stdio.h>

#define MAX_LOCATION_LENGTH 256

struct Tsunami
{
	int month;
	int day;
	int year;
	int dead_count;
	double wave_height;
	char location[MAX_LOCATION_LENGTH];
};

int read_data(char const* file_name, struct Tsunami* arr, int max_cnt);

void print_info(struct Tsunami const* arr, int size, FILE* out_stm);

double get_max_height(struct Tsunami const* arr, int size);

double get_average_height(struct Tsunami const* arr, int size);

void print_height(struct Tsunami const* arr, int size,
	double height, FILE* out_stm);

// TODO: Repeat function documentation block plus function declaration for remaining functions

#endif
