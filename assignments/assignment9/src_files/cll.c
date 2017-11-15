#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cll.h"
#include "josephus.h"

typedef struct soldier_type
{
	char *name;
	struct soldier_type *next;
} soldier;

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

soldier *insert(soldier *cursor, soldier *name)
{
	if (cursor == NULL)
	{
		name->next = name;
		return name;
	}
	else
	{
		soldier *s = cursor;
		for (; s->next != cursor; s = s->next)
			;
		s->next = name;
		name->next = cursor;
		return cursor;
	}
}

soldier *advance(soldier *cursor)
{
	soldier *s = cursor;
	return s->next;
}

soldier *release(soldier *cursor)
{
	//if cursor is only item in list
	if (cursor == cursor->next)
	{
		free(cursor->name);
		free(cursor);
		return NULL;
	}
	else //if more than one item in list
	{
		soldier *s = cursor->next;
		while(s->next != cursor)
		{
			s = s->next;
		}
		s->next = cursor->next;
		free(cursor->name);
		free(cursor);
		return s;
	}
}

soldier print(soldier *cursor)
{
	soldier *s = cursor;
	printf("%s is dead.\n",cursor->name);
}