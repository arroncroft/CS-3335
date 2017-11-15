#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cll.h"

typedef struct soldier_type
{
	char *name;
	struct soldier_type *next;
} soldier;

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
		print(s);
		s = release(s);
	}
	print(s);
	s = release(s);

	return 0;
}
