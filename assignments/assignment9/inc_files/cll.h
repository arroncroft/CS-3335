typedef struct soldier_type soldier;

soldier *create(const char *name);

// Adds a new node after the cursor. 
// For the Josephus program, it is a new soldier,
// whose name comes in as the second argument. 
// Returns the pointer pointing the new node as the new cursor.
void *insert(void *cursor, void *name);

// Advances the cursor by one node and returns it.
void *advance(void *cursor);

// Prints the node pointed by cursor.
// For the Josephus program, the name of the soldier is printed. 
void print(void *cursor);

// Removes the node after the cursor.
// Returns the current cursor.
void *release(void *cursor);

void display(soldier *start);