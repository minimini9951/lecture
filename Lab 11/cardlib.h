#ifndef CARDLIB_H
#define CARDLIB_H

// Pre-processor constants

// Maximum number of cards of input
// 52 + "00" (end indicator)
#define N 53

// Maximum length of an input text string
// * 2 letters each card
// * 1 space separator after each card
// * the end of line sequence (up to 2 characters; in Windows "\r\n")
#define LEN (3 * N + 2)

// Types

typedef unsigned char CardIndex;
typedef char CardSuit;
typedef char CardRank;

typedef struct Card
{
	CardSuit suit;
	CardRank rank;
} Card;

#endif // CARDLIB_H
