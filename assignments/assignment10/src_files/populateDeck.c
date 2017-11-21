#include <stdio.h>
#include <stdlib.h>
#include "sortedHand.h"
#include "populateDeck.h"

typedef enum face_type {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} face;

typedef enum suit_type {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
} suit;

typedef struct card_type
{
    face card_face;
    suit card_suit;
} card;

void populateDeck(card *deck[numFaces][numSuits])
{
    int i, j;
    for (i = 0; i < numFaces; i++)
    {
        for (j = 0; j < numSuits; j++)
        {
            card *c;
            c = create(i, j);
            deck[i][j] = c;
        }
    }
}