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
    soldier *s;
    if ((s = malloc(sizeof(soldier))) == NULL)
    {
        printf("Out of memory on heap.\n");
        return NULL;
    }
    s->name = strdup(name);
    s->next = NULL;
    return s;
}

void *insert(void *cursor, void *name)
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

void *advance(void *cursor)
{
}

void print(void *cursor)
{
}

void *release(void *cursor)
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
        soldier *i = start;
        for (; i != NULL; i = i->next)
        {
            printf("Name: %s\n", i->name);
        }
    }
}
