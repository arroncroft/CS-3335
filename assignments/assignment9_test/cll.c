#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct soldier_type
{
	char *name;
	struct soldier_type *next;
} soldier;

void display(soldier *);

soldier *create(const char *);

// insert_end(h, n) inserts *n at the end of the linked list headed at h and returns the new head
soldier *insert(soldier *, soldier *);

// Advances the cursor by one node and returns it.
soldier *advance(soldier *cursor);

// release(h, name) removes the first record whose name is name (if found) from the linked list headed at h
// and returns the new head.
soldier *release(soldier *, const char *);

// release(h) removes all records (including any referenced items on leap, i.e. names)
// from the linked list recursively
void release_all(soldier *);

soldier print(soldier *cursor);

void display(soldier *start)
{
	if (start == NULL)
	{
		printf("Empty list.\n");
	}
	else
	{
		soldier *i = start;
		for (; i != NULL; i = i->next)
		{
			printf("Name: %s\n", i->name);
		}
	}
}

soldier *create(const char *name)
{
	soldier *s;
	if ((s = malloc(sizeof(soldier))) == NULL)
	{
		printf("Out of memory on heap.\n");
		return NULL;
	}
	//The following is correct.
	s->name = strdup(name);
	strcpy(s->name, name);
	s->next = NULL;

	return s;
}

// insert(cursor, name) inserts *name at the end of the linked list headed at cursor and returns the new head
soldier *insert(soldier *cursor, soldier *name)
{
	if (cursor == NULL)
		return name;
	else
	{
		soldier *s = cursor;
		for (; s->next != NULL; s = s->next)
			;
		s->next = name;
		return cursor;
	}
}

// Advances the cursor by one node and returns it.
soldier *advance(soldier *cursor)
{
	cursor->next = cursor;
}

// release(h, name) removes the first record whose name is name (if found) from the linked list headed at h
// and returns the new head.
soldier *release(soldier *cursor, const char *name)
{
	if (cursor == NULL)
		return NULL;
	else if (strcmp(cursor->name, name) == 0)
	{
		soldier *t = cursor;
		t = t->next;
		free(cursor->name);
		free(cursor);
		return t;
	}
	else
	{
		soldier *pre = cursor;
		soldier *n = pre->next;
		while (n != NULL)
		{
			if (strcmp(n->name, name) == 0)
			{ // found it
				pre->next = n->next;
				free(n->name);
				free(n);
				return cursor;
			}
			else
			{
				pre = n;
				n = n->next;
			}
		}
		return cursor; // not found
	}
}

// release(h) removes all records (including any referenced items on leap, i.e. names)
// from the linked list recursively
/*void release_all(soldier *h)
{
	if (h)
	{
		if (h->name)
			free(h->name);

		struct soldier_type *n = h->next;
		free(h);
		release_all(n);
	}
}*/

// Prints the node pointed by cursor.
// For the Josephus program, the name of the soldier is printed. 
soldier print(soldier *cursor);

int main()
{
	soldier *start = NULL;
	soldier *s;
	char name[80];
	for (; fgets(name, sizeof(name), stdin) != NULL;)
	{
		name[strlen(name) - 1] = '\0';
		if ((s = create(name)) == NULL)
			return 1;
		start = insert(start, s);
	}
	display(start);
	return 0;
}
