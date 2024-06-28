#include <stdio.h>
#include <string.h>
#include "gamelib.h"

void load_game(const char text[], Card game[])
{
    int i = 0, j = 0;
    while (text[i] != '0' || text[i + 1] != '0') {
        game[j].suit = text[i];
        game[j].rank = text[i + 1];
        i += 3; // Move to the next card in the text
        j++;
    }
    game[j].suit = '0';
    game[j].rank = '0';
}

void del_card(Card game[], int index)
{
    int i = index;
    while (game[i].suit != '0' || game[i].rank != '0') {
        game[i] = game[i + 1];
        i++;
    }
}

void play_game(Card game[])
{
    int i;

    for (i = 0; game[i].suit != '0' || game[i].rank != '0'; i++) {

        if (i >= 3 && (game[i].suit == game[i - 3].suit || game[i].rank == game[i - 3].rank)) {
            game[i - 3] = game[i];
            del_card(game, i);
            i -= 4; // Move back to re-check after modification
        }
        else if (i >= 1 && (game[i].suit == game[i - 1].suit || game[i].rank == game[i - 1].rank)) {
            game[i - 1] = game[i];
            del_card(game, i);
            i -= 2; // Move back to re-check after modification
        }
    }
}

void display_game(const Card game[])
{
    int i = 0;
    while (game[i].suit != '0' || game[i].rank != '0') {
        printf("%c%c ", game[i].suit, game[i].rank);
        i++;
    }
    printf("00 \n");
}