#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "displayBoard.h"

void displayBoard(int percentOrgs, int a, int b, char board[a][b])
{
    int i, j;

    system("clear"); //clear terminal
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            printf("%c", board[i][j]);
            printf("  "); //fill up board
        }
        printf("%d\n", i+1); //add vertical numbers
    }

    for (i = 1; i <= b; i++)
    {
        //add horizontal numbers
        if (i < 10)
            printf("%d  ", i);
        else
            printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
    usleep(200000);
}
