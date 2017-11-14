typedef struct soldier_type soldier;

soldier *create(const char *);

// Adds a new node after the cursor. 
// For the Josephus program, it is a new soldier,
// whose name comes in as the second argument. 
// Returns the pointer pointing the new node as the new cursor.
soldier *insert(soldier *cursor, soldier *name);

// Advances the cursor by one node and returns it.
soldier *advance(soldier *cursor);

// Removes the node after the cursor.
// Returns the current cursor.
soldier *release(soldier *cursor);

// Prints the node pointed by cursor.
// For the Josephus program, the name of the soldier is printed. 
soldier print(soldier *cursor);

void display(soldier *start);