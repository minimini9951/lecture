#include "add_digit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BigNumber {
    BigDigit* digits;
    size_t length;
};


BigNumber* create_BigNumber(const char* text)
{
    struct BigNumber* bignumber = (BigNumber*)malloc(sizeof(BigNumber));
    int i;
    bignumber->length = strlen(text);
    bignumber->digits = (BigDigit*)malloc(bignumber->length * sizeof(text));
    for (i = 0; i < (int)bignumber->length; i++)
    {
        bignumber->digits[i] = (BigDigit)(*(text + i) - '0');
    }
    return bignumber;
}

void destroy_BigNumber(BigNumber* number)
{
    free(number->digits);
}

BigNumber* add_BigNumber(const BigNumber* number1, const BigNumber* number2)
{
    const struct BigNumber* bigger = number1->length >= number2->length ? number1 : number2;
    struct BigNumber* number3 = (BigNumber*)malloc(sizeof(BigNumber));
    number3->length = bigger->length;
    number3->digits = (BigDigit*)malloc(bigger->length * sizeof(char));
    int i;
    BigDigit carry = 0;
    for (i = 1; i <= (int)bigger->length; i++)
    {
        int number1_idx = (int)number1->length - i; //;
        int number2_idx = (int)number2->length - i; //;
        if (number1_idx < 0)
            number3->digits[(int)bigger->length - i] = add_BigDigit(0, number2->digits[number2_idx], &carry);
        else if (number2_idx < 0)
            number3->digits[(int)bigger->length - i] = add_BigDigit(number1->digits[number1_idx], 0, &carry);
        else
            number3->digits[(int)bigger->length - i] = add_BigDigit(number1->digits[number1_idx], number2->digits[number2_idx], &carry);
    }
    return number3;
}

void print_BigNumber_sum(const BigNumber* number1, const BigNumber* number2, const BigNumber* sum)
{
    const struct BigNumber* bigger;
    if (number1->length >= number2->length && number1->length >= sum->length)
        bigger = number1;
    if (number2->length >= number1->length && number2->length >= sum->length)
        bigger = number2;
    if (sum->length >= number1->length && sum->length >= number2->length)
        bigger = sum;

    int i;
    printf("  ");
    //print number1
    for (i = 0; i < (int)bigger->length - (int)number1->length; i++)
        printf(" ");
    for (i = 0; i < (int)number1->length; i++)
        printf("%c", number1->digits[i] + '0');
    printf("\n");
    printf("+ ");
    //print number2
    for (i = 0; i < (int)bigger->length - (int)number2->length; i++)
        printf(" ");
    for (i = 0; i < (int)number2->length; i++)
        printf("%c", number2->digits[i] + '0');
    printf("\n");
    printf("--");
    for (i = 0; i < (int)bigger->length; i++)
        printf("-");
    printf("\n");
    printf("  ");
    //print sum
    for (i = 0; i < (int)bigger->length - (int)sum->length; i++)
        printf(" ");
    for (i = 0; i < (int)sum->length; i++)
        printf("%c", sum->digits[i] + '0');
    printf("\n");
}
