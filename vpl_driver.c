#include "dynamicArrays.h"
#include <stdio.h>

//Prints the array
void PrintArray(struct ARRAY arr)
{
	int i = 0;

	if(arr.size <= 0)
		printf("ERROR. SIZE IS %d", arr.size);
	else
		printf("PRINTING ARRAY OF SIZE %d \n", arr.size);

	for (i = 0; i < arr.size; i++)
	{
		//Print an array using pointer syntax
		printf(" %d", *(arr.Pointer + i));
	}

	printf("\n");
}

void RunCase1(void)
{
	printf("\n Running Case 1: \n\n");

	struct ARRAY arr;

	int s = 5;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	for (int i = 0; i < s; i++)
	{
		arr.Pointer[i] = i + 1;
	}

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase2(void)
{
	printf("\n Running Case 2: \n\n");

	struct ARRAY arr;

	int s = -5;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase3(void)
{
	printf("\n Running Case 3: \n\n");

	struct ARRAY arr;

	int s = 0;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase4(void)
{
	printf("\n Running Case 4: \n\n");
	struct ARRAY arr;

	int s = 10;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	for (int i = 0; i < s; i++)
	{
		arr.Pointer[i] = i + 1;
	}

	struct ARRAY arr2 = arr;	 //We are trying to copy "half" the array
	arr2.Pointer += s / 2;		 //
	arr2.size = s / 2;			 //


	PrintArray(arr);
	PrintArray(arr2);

	FreeArray(&arr);
	//FreeArray(&arr2);			 //Uncommenting This SHOULD crash			
}

void RunCase5(void)
{
	printf("\n Running Case 5: \n\n");
	struct ARRAY arr;

	int s = 4;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	for (int i = 0; i < 3 * s; i++)
	{
		PushBack(&arr, i + 1);
	}

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase6(void)
{
	printf("\n Running Case 6: \n\n");
	struct ARRAY arr;

	int s = 100;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	for (int i = 0; i < s; i++)
	{
		PushBack(&arr, i + 1);
	}

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase7(void)
{
	printf("\n Running Case 7: \n\n");
	struct ARRAY arr;

	int s = 0;

	arr.Pointer = AllocateArrayUserSize(&s);
	arr.size = s;

	for (int i = 0; i < s; i++)
	{
		PushBack(&arr, i + 1);
	}

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase8(void)
{
	printf("\n Running Case 8: \n\n");
	struct ARRAY arr;

	int s = 0;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	s = 4;

	for (int i = 0; i < s; i++)
	{
		PushBack(&arr, i + 1);
	}

	PrintArray(arr);
	FreeArray(&arr);
}

void RunCase9(void)
{
	printf("\n Running Case 9: \n\n");
	struct ARRAY arr;

	int s = -5;

	arr.Pointer = AllocateArray(s);
	arr.size = s;

	s = 4;

	for (int i = 0; i < s; i++)
	{
		PushBack(&arr, i + 1);
	}

	PrintArray(arr);
	FreeArray(&arr);
}


int main(void)
{
	RunCase1();	//Array of normal size
	RunCase2();	//Array of negative size
	RunCase3();	//Array of size 0
	RunCase4();	//duplicating arrays
	RunCase5();	//Multiple grows of the array using push back
	RunCase6();	//Sigle Grow

	RunCase7();	//User input test. Given output is with number 42
	RunCase7();	//User input test. Given output is with number 24

	RunCase8();	//Grow a size 0 array
	RunCase9();	//Grow an array of negative size

	return 0;
}