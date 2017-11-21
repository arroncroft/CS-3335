#include <stdio.h>
#include <stdlib.h>
#include "sortedHand.h"
#include "compare.h"

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

int compare_face(const void *c1, const void *c2)
{
    int a = ((struct card_type *)c1)->card_face;
    int b = ((struct card_type *)c2)->card_face;
    return b - a;
}

int compare_suit(const void *c1, const void *c2)
{
    int a = ((struct card_type *)c1)->card_suit;
    int b = ((struct card_type *)c2)->card_suit;
    return b - a;
}