// @todo: Add a file-level documentation header as explained in Lab 2 specs ...

#include <stdio.h> // for FILE*

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// initialize, wc, and print_freqs

void initialize(int latin_freq[], int size, int* ctrl_cnt, int* non_latin_cnt);

void wc(FILE* ifs, int latin_freq[], int* ctrl_cnt, int* non_latin_cnt);

void print_freqs(int const latin_freq[], int size, int const* ctrl_cnt, int const* non_latin_cnt);

int is_upper(int ch);

int is_lower(int* ch);

int is_latin(int* ch);