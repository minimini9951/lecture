#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#undef max
#undef min

#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]

// TODO: Include all necessary C standard library headers 

// TODO: Definitions of functions declared in q.h go here ...

double* read_data(char const* file_name, int* ptr_cnt)
{
	FILE* file = fopen(file_name, "r");
	if (file == NULL) {
		return NULL;
	}

	size_t count = 0;
	double temp;

	while (fscanf(file, "%lf", &temp) == 1) {
		count++;
	}

	if (count == 0) {
		fclose(file);
		return NULL;
	}

	*ptr_cnt = count;

	double* data = (double*)malloc(count * sizeof(double));
	if (data == NULL) {
		fclose(file);
		return NULL;
	}

	rewind(file);

	size_t i = 0;
	while (i < count && fscanf(file, "%lf", &data[i]) == 1) {
		i++;
	}

	fclose(file);

	return data;
}

double max(double const* begin, double const* end)
{
	double num = begin[0];
	int count = end - begin;

	for (int i = 1; i < count; ++i)
	{
		if (begin[i] > num)
			num = begin[i];
	}
	return num;
}

double min(double const* begin, double const* end)
{
	double num = begin[0];
	int count = end - begin;

	for (int i = 1; i < count; ++i)
	{
		if (begin[i] < num)
			num = begin[i];
	}
	return num;
}

int find_min_pos(double const* begin, double const* end)
{
	double num = begin[0];
	int count = end - begin;

	for (int i = 1; i < count; ++i)
	{
		if (begin[i] < num)
			num = begin[i];
	}

	for (int i = 0; i < count; i++)
		if (num == begin[i])
			return i;
	return 0;
}

double average(double const* begin, double const* end)
{
	double sum = 0.0;
	int count = end - begin;

	for (int i = 0; i < count; ++i)
	{
		sum += begin[i];
	}

	return sum / count;
}

double variance(double const* begin, double const* end)
{
	double aver = average(begin, end);
	double sum = 0.0;
	int count = end - begin;
	for (int i = 0; i < count; i++)
	{
		sum += (begin[i] - aver) * (begin[i] - aver);
	}

	return sum / (count - 1);
}

double std_dev(double const* begin, double const* end)
{
	double varian = variance(begin, end);

	return sqrt(varian);
}

double median(double* base, int size)
{
	double mid_num = 0;
	double mid_num2 = 0;
	selection_sort(base, size);
	if (size % 2 == 0)
	{
		mid_num = *(base + size / 2);
		mid_num2 = *(base + size / 2 - 1);
		return (mid_num + mid_num2) / 2.0;
	}
	else
	{
		mid_num = *(base + (size / 2));
		return mid_num;
	}
}

void selection_sort(double* base, int size)
{
	for (int i = 0; i < size; i++)
	{
		double cpy_base = *(base + i);
		double min_val = min(base + i, base + size);
		int min_pos = i + find_min_pos(base + i, base + size);

		*(base + i) = min_val;
		*(base + min_pos) = cpy_base;
	}
}

double count_grade(double const* begin, double const* end, double* ltr_grades, char alp)
{
	int count = 0;
	for (int i = 0; i < end - begin; i++)
	{
		if (*(ltr_grades + i) == alp)
			count++;
	}
	return count / (end - begin);
}

void ltr_grade_pctg(double const* begin, double const* end, double* ltr_grades)
{
	double count_A = 0;
	double count_B = 0;
	double count_C = 0;
	double count_D = 0;
	double count_F = 0;
	double count = end - begin;
	for (int i = 0; i < count; i++)
	{
		if (*(begin + i) >= 90)
		{
			count_A++;
		}
		else if (*(begin + i) >= 80)
		{
			count_B++;
		}
		else if (*(begin + i) >= 70)
		{
			count_C++;
		}
		else if (*(begin + i) >= 60)
		{
			count_D++;
		}
		else
		{
			count_F++;
		}
	}
	ltr_grades[0] = (count_A * 100) / count;
	ltr_grades[1] = (count_B * 100) / count;
	ltr_grades[2] = (count_C * 100) / count;
	ltr_grades[3] = (count_D * 100) / count;
	ltr_grades[4] = (count_F * 100) / count;
}
