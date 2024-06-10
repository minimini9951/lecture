#include "q.h"

int read_data(char const* file_name, struct Tsunami* arr, int max_cnt)
{
	FILE* file = fopen(file_name, "r");
	if (!file) {
		fprintf(stderr, "Error opening file %s\n", file_name);
		return 0;
	}
	int count = 0;
	while (count < max_cnt && fscanf(file, "%d %d %d %d %lf %[^\n]",
		&arr[count].month, &arr[count].day,
		&arr[count].year, &arr[count].dead_count,
		&arr[count].wave_height, arr[count].location) == 6) {
		count++;
	}

	fclose(file);
	return count;
}

void print_info(struct Tsunami const* arr, int size, FILE* out_stm)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(out_stm, "%02d %02d %4d %6d %5.2f %s\n",
			arr[i].month, arr[i].day, arr[i].year,
			arr[i].dead_count, arr[i].wave_height,
			arr[i].location);
	}
}

double get_max_height(struct Tsunami const* arr, int size)
{
	double max_height = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].wave_height > max_height)
		{
			max_height = arr[i].wave_height;
		}
	}
	return max_height;
}

double get_average_height(struct Tsunami const* arr, int size)
{
	double total_height = 0.0;
	for (int i = 0; i < size; ++i) {
		total_height += arr[i].wave_height;
	}
	return size > 0 ? total_height / size : 0.0;
}

void print_height(struct Tsunami const* arr, int size, double height, FILE* out_stm)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].wave_height > height)
		{
			fprintf(out_stm, "%5.2f %s\n", arr[i].wave_height, arr[i].location);
		}
	}
}
