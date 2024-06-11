#include "q.h"

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count)
{
	size_t par_len = STRLEN(parent);
	size_t sep_len = 0;
	size_t fol_len = 0;
	for (int i = 0; i < (int)count; i++)
	{
		fol_len += STRLEN(folders[i]);
		sep_len++;
	}

	char* str = debug_malloc(par_len + sep_len + fol_len + 1);
	
	STRCPY(str, parent);
	for (int i = 0; i < (int)count; i++)
	{
		STRCAT(str, folders[i]);
		STRCAT(str, separator);
	}

	return str;
}

void compare_string(const char* lhs, const char* rhs)
{
	int result = STRCMP(lhs, rhs);
	if (result < 0) {
		printf("Left string goes first.\n");
	}
	else if (result == 0) {
		printf("Both strings are equal.\n");
	}
	else {
		printf("Right string goes first.\n");
	}
}

void describe_string(const char* text)
{
	int length = (int)STRLEN(text);
	printf("The length of the path \"%s\" is %d.\n", text, length);
}

void find_string(const char* string, const char* substring)
{
	printf("Searching for a string:\n");
	printf("\tText:     %s\n", string);
	printf("\tSub-text: %s\n", substring);
	char* position = STRSTR(string, substring);
	if (position)
	{
		printf("\tResult:   found %zu characters at a position %ld.\n",
			STRLEN(substring), position - string);
	}
	else
	{
		printf("\tResult:   not found\n");
	}
}
