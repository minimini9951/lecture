#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int can_open(FILE* file)
{
	if (file == NULL) {
		printf("Unable to open file plain.txt");
		return 0;
	}
	else
	{
		return 1;
	}
}

int text_length(FILE* file)
{
	char ch = 0;
	int length = 0;
	while ((ch = (char)fgetc(file)) != EOF) {
		length++;
	}
	return length;
}

char* make_space(unsigned int length)
{
	return (char*)malloc((length + 1) * sizeof(char));
}

void text_content(int length, char* content, FILE* file)
{
	int value = 0;
	while (value < length && (content[value] = (char)fgetc(file)) != EOF)
	{
		value++;
	}
	content[value] = '\0';
}

void encrypt(char* letter, char *keytext, int letter_length,
	int key_length)
{
	for (int i = 0; i < letter_length; i++)
	{
		*(letter + i) += *(keytext + (i % key_length));
	}
	printf("letter is changed to '%c'", *letter);
}

void decrypt(char* letter, char *keytext, int letter_length,
	int key_length)
{
	for (int i = 0; i < letter_length; i++)
	{
		*(letter + i) -= *(keytext + (i % key_length));
	}
	printf("letter is changed to '%c'", *letter);
}
