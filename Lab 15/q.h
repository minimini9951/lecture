// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
#include <stdio.h>
// @todo: Copy type aliases and macros from the current specs

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...
struct Datum
{
	char upper;
	char lower;
	unsigned short int value;
};

typedef struct Datum DATUM;
typedef DATUM DATA[2];
// @todo: Now, provide the declaration or prototype of the function print_data
void print_data(const void* ptr, size_t size, size_t span);