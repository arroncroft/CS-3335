typedef struct soldier_type soldier;

void display(soldier *);

soldier *create(const char *);

soldier *insert(soldier *, soldier *);

soldier *advance(soldier *cursor);

soldier *release(soldier *, const char *);

void release_all(soldier *);

soldier print(soldier *cursor);