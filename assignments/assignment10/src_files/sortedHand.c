#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortedHand.h"
#include "populateDeck.h"
#include "compare.h"

const char *faceNames[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "ace"};
const char *suitNames[] = {"spades", "hearts", "diamonds", "clubs"};

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
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS,
} suit;

typedef struct card_type
{
    face card_face;
    suit card_suit;
} card;

card *create(int face, int suit)
{
    card *c;
    if ((c = malloc(sizeof(card))) == NULL)
    {
        printf("Out of memory on heap.\n");
        return NULL;
    }
    c->card_face = face;
    c->card_suit = suit;

    return c;
}

void *print(card *c)
{
    printf("card: %5s of %-8s\n", faceNames[c->card_face], suitNames[c->card_suit]);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int i, f, s;
    card *deck[numFaces][numSuits];
    int used[numFaces][numSuits] = {0};
    card *hand[handSize];

    //create deck of cards
    populateDeck(deck);
    printf("Here is a 10-card hand that was dealt randomly by the machine:\n\n");
    //add 10 unique random cards to hand
    for (i = 0; i < handSize;)
    {
        //draw randomly from deck
        f = rand() % numFaces;
        s = rand() % numSuits;
        //make sure there are no repeats
        if (used[f][s] == 0)
        {
            hand[i] = deck[f][s];
            used[f][s] = 1;
            i++;
        }
    }
    //sort by face, then by suit
    qsort(hand, sizeof(hand) / sizeof(card *), sizeof(card *), compare_face);
    qsort(hand, sizeof(hand) / sizeof(card *), sizeof(card *), compare_suit);
    //print hand array
    for (i = 0; i < handSize; i++)
    {
        print(hand[i]);
    }

    return 0;
}