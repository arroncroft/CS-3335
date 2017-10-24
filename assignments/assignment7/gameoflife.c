#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include "displayBoard.h"
#include "generateOrganisms.h"

int main(int argc, char *argv[])
{
    //default board settings
    int percentOrgs = 10;
    int boardHeight = 30;
    int boardWidth = 30;

    argc -= optind;
    argv += optind;

    //accept inputs for organism percent, board height, and board width
    if (argc == 1)
    {
        percentOrgs = atoi(argv[0]);
    }
    else if (argc == 2)
    {
        boardHeight = atoi(argv[0]);
        boardWidth = atoi(argv[1]);
    }
    else if (argc == 3)
    {
        percentOrgs = atoi(argv[0]);
        boardHeight = atoi(argv[1]);
        boardWidth = atoi(argv[2]);
    }
    else if (argc > 3)
    {
        fprintf(stderr, "Error: more than 3 inputs\n");
        exit(0);
    }

    //create 2d array for board 
    char board[boardHeight][boardWidth];
    //create pointer to pass to generateOrganisms
    char (*ptr)[boardWidth];
    ptr = board;
    
    //populate arrays with spaces
    int i, j;
    srand(time(NULL));
    for (i = 0; i < boardHeight; i++)
    {
        for (j = 0; j < boardWidth; j++)
        {
            int r = (rand() % 100) + 1;
            if (r <= percentOrgs)
                board[i][j] = 'X';
            else
                board[i][j] = ' ';
        }
    }

    //loop generating organisms and displaying them on the board
    while (1)
    {
        generateOrganisms(percentOrgs, boardHeight, boardWidth, ptr);
        displayBoard(percentOrgs, boardHeight, boardWidth, board);
    }
}
