#include "my_string.h"

size_t my_strlen(const char* str)
{
	int length = 0;
	for (; *str != '\0'; str++, length++);

	return (size_t)length;
}

char* my_strcpy(char* dest, const char* src)
{
	for (int i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
		i++;

		*dest = *src;
		dest++;
		src++;
	}
	return dest;
}

char* my_strcat(char* dest, const char* src)
{
	char* des = dest;
	while (*des != '\0')
	{
		des++;
	}
	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}

	*des = '\0';

	return dest;
}

int my_strcmp(const char* lhs, const char* rhs)
{
	if (*lhs < *rhs)
	{
		return -1;
	}
	else if (*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

char* my_strstr(const char* str, const char* substr)
{
	if (!*substr) {
		return (char*)str;
	}

	for (const char* h = str; *h; ++h)
	{
		const char* h1 = h;
		const char* n = substr;

		while (*h1 && *n && *h1 == *n) {
			++h1;
			++n;
		}

		if (!*n)
		{
			return (char*)h;
		}
	}

	return NULL;
}