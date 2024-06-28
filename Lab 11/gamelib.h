#ifndef GAMELIB_H
#define GAMELIB_H

#include "cardlib.h"

// Loads a game by reading it from text[] into the array of cards.
void load_game(const char text[], Card game[]);

// Plays a game.
void play_game(Card game[]);

// Displays the sequence of cards.
void display_game(const Card game[]);

#endif // GAMELIB_H
