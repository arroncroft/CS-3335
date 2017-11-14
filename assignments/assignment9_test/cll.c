#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		return s->next;
	}
}

soldier print(soldier *cursor)
{
	soldier *s = cursor;
	printf("Cursor is on: %s\n",cursor->name);
}

void display(soldier *cursor)
{
    soldier *temp = cursor;
    if (cursor != NULL)
    {
    	printf("\t\t");
        do
        {
            printf("%s\t\t", temp->name);
            temp = temp->next;
        }
        while (temp != cursor);
    }
    printf("\n\n");
}

int main()
{
	soldier *start = NULL;
	soldier *s;
	char name[80];
	int order;
	int i;
	
	printf("Enter the names of soldiers (one per line, Ctrl-D to finish):\n");
	for (; fgets(name, sizeof(name), stdin) != NULL;)
	{
		name[strlen(name) - 1] = '\0';
		if ((s = create(name)) == NULL)
			return 1;
		start = insert(start, s);
	}
	printf("The soldiers are:");
	display(s);
	printf("Enter the elimination order: ");
	scanf("%d", &order);
	printf("\n");
	
	while(s != s->next)
	{
		for(i = 0; i < order; i++)
		{
			s = advance(s);
		}
		s = release(s);
		printf("%s is dead.", s->name);
	}


	
	return 0;
}
