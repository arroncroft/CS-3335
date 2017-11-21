#define handSize 10
#define numFaces 13
#define numSuits 4

typedef enum face_type face;

typedef enum suit_type suit;

typedef struct card_type card;

card *create(int, int);

void *print(card *);