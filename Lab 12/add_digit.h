#ifndef ADD_DIGIT_H
#define ADD_DIGIT_H

struct BigNumber;

typedef unsigned char BigDigit;
typedef struct BigNumber BigNumber;

extern BigNumber* create_BigNumber(
	const char* text
);

extern void destroy_BigNumber(
	BigNumber* number
);

extern BigNumber* add_BigNumber(
	const BigNumber* number1,
	const BigNumber* number2
);

extern void print_BigNumber_sum(
	const BigNumber* number1,
	const BigNumber* number2,
	const BigNumber* sum
);

BigDigit add_BigDigit(
	BigDigit digit1,
	BigDigit digit2,
	BigDigit* carry
);

#endif
