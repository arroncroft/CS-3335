#include "cll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[80];
    char prevName[80];
    soldier *s;
    int i = 0;

    for (; fgets(name, sizeof(name), stdin) != NULL;)
    {
        name[strlen(name) - 1] = '\0';
        if (i == 0)
        {
            if ((s = create(name)) == NULL)
                return 1;
            insert(NULL, name);
            strcpy(prevName, name);
            i++;
        }
        else
        {
            if ((s = create(name)) == NULL)
                return 1;
            insert(prevName, name);
            strcpy(prevName, name);
        }
    }

    return 0;
}