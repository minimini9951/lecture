#pragma once

#include <stdlib.h>

struct ARRAY
{
	int* Pointer;
	int size;
};

/*
	Prints the values of the array given by the pointer and size
	Implemented in the driver
*/
void PrintArray(struct ARRAY arr);


/*	Allocates memory to hold an array of <size> ints.
	Initial values are all 0
	Returns a pointer to the Array
	Returns NULL if it could not be created
*/
int* AllocateArray(int size);

/*	Allocates memory to hold an array of <User Input> ints.
	Returns a pointer to the Array
	Returns NULL if it could not be created
*/
int* AllocateArrayUserSize(int * size);

/*	
	Frees the memory of the int array given by the pointer
*/
void FreeArray(struct ARRAY * arr);

/*
	Tries to PushBack the <value> to the first zero
	value of the array. If the array is full, it will duplicate
	its size
*/
void PushBack(struct ARRAY * arr, int value);