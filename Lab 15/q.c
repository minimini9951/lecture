// @todo: Add a file documentation header as explained in the specs ...
#include "q.h"
// @todo: Add necessary C standard library headers here ...
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in q.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...

void print_data(const void* ptr, size_t size, size_t span)
{
	int i, j;
	int count = 0;
	char* c_ptr = (char*)ptr;
	for (j = 0; j < (int)(size / span); j++)
	{
		for (i = 0; i < (int)span; i++)
		{
			printf("%x ", *(c_ptr + i + count));
			if (i % 4 == 3)
				printf("  ");
		}
		printf("|  ");
		for (i = 0; i < (int)span; i++)
		{
			printf(" %c", *(c_ptr + i + count));
			if (i % 4 == 3 && i != (int)span - 1)
				printf("  ");
		}
		printf("\n");
		count += i;
	}
}
