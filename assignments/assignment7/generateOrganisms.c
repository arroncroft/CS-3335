#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generateOrganisms.h"

/*
Rules: 
1. New organism can be born in spot with exactly 3 neighbors
2. Organisms with less than 2 or more than 3 neighbors will die
3. Organisms with 2 or 3 neighbors survive
4. Top row and bottom row are neighbors, leftmost and rightmost columns are neighbors
*/

void generateOrganisms(int percentOrgs, int a, int b, char board[][b])
{
    int i, j;
    int neighbors;
    srand(time(NULL));

    //should either be " " or "X"
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            //count neighbors
            //death
            //birth
            int r = (rand() % 100) + 1;
            if (r <= percentOrgs)
                board[i][j] = 'X';
        }
    }
}