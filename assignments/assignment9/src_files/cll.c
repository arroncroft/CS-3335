#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cll.h"

typedef struct soldier_type
{
    char *name;
    struct soldier_type *next;
} soldier;

soldier *create(const char *name)
{
    soldier *i;
    if ((i = malloc(sizeof(soldier))) == NULL)
    {
        printf("Out of memory on heap.\n");
        return NULL;
    }
    i->name = strdup(name);
    strcpy(i->name, name);
    i->next = NULL;

    return i;
}

soldier *insert(soldier *cursor, soldier *name)
{
    if (cursor == NULL)
        return name;
    else
    {
        soldier *s = cursor;
        for (; s->next != NULL; s = s->next)
            ;
        s->next = s;
        return s;
    }
}

soldier *advance(soldier *cursor)
{
}

soldier print(soldier *cursor)
{
}

soldier *release(soldier *cursor)
{
}

void display(soldier *start)
{
    if (start == NULL)
    {
        printf("Empty list.\n");
    }
    else
    {
        soldier *s = start;
        for (; s != NULL; s = s->next)
        {
            printf("Name: %s\n", s->name);
        }
    }
}

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
