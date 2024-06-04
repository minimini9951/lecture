#include <stdio.h> 

#define diff ('a' - 'A')

int is_upper(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return 1;
	}
	else
		return 0;
}

int is_lower(int* ch)
{
	if (*ch >= 'a' && *ch <= 'z')
	{
		*ch -= diff;
		return 1;
	}
	else
		return 0;
}

int is_latin(int* ch) {
	return is_upper(*ch) || is_lower(ch);
}

void initialize(int latin_freq[], int size, int* ctrl_cnt, int* non_latin_cnt)
{
	for (int i = 0; i < size; i++)
	{
		latin_freq[i] = 0;
	}
	*ctrl_cnt = 0;
	*non_latin_cnt = 0;
}

void wc(FILE* ifs, int latin_freq[], int* ctrl_cnt, int* non_latin_cnt)
{
	int ch;
	while ((ch = fgetc(ifs)) != EOF)
	{
		if (is_latin(&ch))
		{
			latin_freq[ch - 'A']++;
		}
		else if (ch == '\a' || ch == '\b' || ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v')
		{
			(*ctrl_cnt)++;
		}
		else
		{
			(*non_latin_cnt)++;
		}
	}
}

void print_freqs(int const latin_freq[], int size, int const* ctrl_cnt, int const* non_latin_cnt)
{
	int latin_sum= 0;
	for (int i = 0; i < size; i++)
	{
		printf("%-10c", i + 'a');
	}
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%-10d", latin_freq[i]);
		latin_sum += latin_freq[i];
	}
	printf("\n");
	printf("\n");
	printf("Latin Letters     :%8d\n", latin_sum);
	printf("Non-Latin Letters :%8d\n", *non_latin_cnt);
	printf("Control Letters   :%8d\n", *ctrl_cnt);
}
