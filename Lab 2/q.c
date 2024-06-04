#include "q.h"
// @todo: Add a file documentation header as explained in the specs ...

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

#define diff 'a' - 'A'

char* str_to_upper(char* string)
{
	for (int i = 0; *(string + i) != '\0'; i++)
	{
		if (*(string + i) >= 'a' && *(string + i) <= 'z')
		{
			*(string + i) += diff;
		}
	}
	return string;
}

WordCount words_starting_with(const char* dictionary, char letter)
{

	return WordCount();
}

ErrorCode spell_check(const char* dictionary, const char* word)
{
	return ErrorCode();
}

ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count)
{
	return ErrorCode();
}

ErrorCode info(const char* dictionary, DictionaryInfo* info)
{
	return ErrorCode();
}
