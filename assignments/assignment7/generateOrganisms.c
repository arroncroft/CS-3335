#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generateOrganisms.h"

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
            neighbors = 0;
            //inside rows and columns
            if ((i != 0) && (i != a - 1) && (j != 0) && (j != b - 1))
            {
                if (board[i + 1][j] == 'X') //up
                    neighbors++;
                if (board[i - 1][j] == 'X') //down
                    neighbors++;
                if (board[i][j - 1] == 'X') //left
                    neighbors++;
                if (board[i + 1][j - 1] == 'X') //up left
                    neighbors++;
                if (board[i - 1][j - 1] == 'X') //down left
                    neighbors++;
                if (board[i][j + 1] == 'X') //right
                    neighbors++;
                if (board[i + 1][j + 1] == 'X') //up right
                    neighbors++;
                if (board[i - 1][j + 1] == 'X') //down right
                    neighbors++;
            }
            //4 outside rows
            if (i == 0 && j != 0 && j != b - 1) //top row
            {
                if (board[a - 1][j] == 'X') //up
                    neighbors++;
                if (board[i - 1][j] == 'X') //down
                    neighbors++;
                if (board[i][j - 1] == 'X') //left
                    neighbors++;
                if (board[a - 1][j - 1] == 'X') //up left
                    neighbors++;
                if (board[i - 1][j - 1] == 'X') //down left
                    neighbors++;
                if (board[i][j + 1] == 'X') //right
                    neighbors++;
                if (board[a - 1][j + 1] == 'X') //up right
                    neighbors++;
                if (board[i - 1][j + 1] == 'X') //down right
                    neighbors++;
            }
            if (i == a - 1 && j != 0 && j != b - 1) //bottom row
            {
                if (board[i + 1][j] == 'X') //up
                    neighbors++;
                if (board[0][j] == 'X') //down
                    neighbors++;
                if (board[i][j - 1] == 'X') //left
                    neighbors++;
                if (board[i + 1][j - 1] == 'X') //up left
                    neighbors++;
                if (board[0][j - 1] == 'X') //down left
                    neighbors++;
                if (board[i][j + 1] == 'X') //right
                    neighbors++;
                if (board[i + 1][j + 1] == 'X') //up right
                    neighbors++;
                if (board[0][j + 1] == 'X') //down right
                    neighbors++;
            }
            if (j == 0 && i != 0 && i != a - 1) //left column
            {
                if (board[i + 1][j] == 'X') //up
                    neighbors++;
                if (board[i - 1][j] == 'X') //down
                    neighbors++;
                if (board[i][b - 1] == 'X') //left
                    neighbors++;
                if (board[i + 1][b - 1] == 'X') //up left
                    neighbors++;
                if (board[i - 1][b - 1] == 'X') //down left
                    neighbors++;
                if (board[i][j + 1] == 'X') //right
                    neighbors++;
                if (board[i + 1][j + 1] == 'X') //up right
                    neighbors++;
                if (board[i - 1][j + 1] == 'X') //down right
                    neighbors++;
            }
            if (j == b - 1 && i != 0 && i != a - 1) //right column
            {
                if (board[i + 1][j] == 'X') //up
                    neighbors++;
                if (board[i - 1][j] == 'X') //down
                    neighbors++;
                if (board[i][j - 1] == 'X') //left
                    neighbors++;
                if (board[i + 1][j - 1] == 'X') //up left
                    neighbors++;
                if (board[i - 1][j - 1] == 'X') //down left
                    neighbors++;
                if (board[i][0] == 'X') //right
                    neighbors++;
                if (board[i + 1][0] == 'X') //up right
                    neighbors++;
                if (board[i - 1][0] == 'X') //down right
                    neighbors++;
            }
            //4 corners
            if (i == 0 && j == 0) //top left corner
            {
                if (board[a - 1][j] == 'X') //up
                    neighbors++;
                if (board[i - 1][j] == 'X') //down
                    neighbors++;
                if (board[i][b - 1] == 'X') //left
                    neighbors++;
                if (board[a - 1][b - 1] == 'X') //up left
                    neighbors++;
                if (board[i - 1][b - 1] == 'X') //down left
                    neighbors++;
                if (board[i][j + 1] == 'X') //right
                    neighbors++;
                if (board[a - 1][j + 1] == 'X') //up right
                    neighbors++;
                if (board[i - 1][j + 1] == 'X') //down right
                    neighbors++;
            }
            if (i == 0 && j == b - 1) //top right corner
            {
                if (board[a - 1][j] == 'X') //up
                    neighbors++;
                if (board[i - 1][j] == 'X') //down
                    neighbors++;
                if (board[i][j - 1] == 'X') //left
                    neighbors++;
                if (board[a - 1][j - 1] == 'X') //up left
                    neighbors++;
                if (board[i - 1][j - 1] == 'X') //down left
                    neighbors++;
                if (board[i][0] == 'X') //right
                    neighbors++;
                if (board[a - 1][0] == 'X') //up right
                    neighbors++;
                if (board[i - 1][0] == 'X') //down right
                    neighbors++;
            }
            if (i == a - 1 && j == 0) //bottom left corner
            {
                if (board[i + 1][j] == 'X') //up
                    neighbors++;
                if (board[0][j] == 'X') //down
                    neighbors++;
                if (board[i][b - 1] == 'X') //left
                    neighbors++;
                if (board[i + 1][b - 1] == 'X') //up left
                    neighbors++;
                if (board[0][b - 1] == 'X') //down left
                    neighbors++;
                if (board[i][j + 1] == 'X') //right
                    neighbors++;
                if (board[i + 1][j + 1] == 'X') //up right
                    neighbors++;
                if (board[0][j + 1] == 'X') //down right
                    neighbors++;
            }
            if (i == a - 1 && j == b - 1) //bottom right corner
            {
                if (board[i + 1][j] == 'X') //up
                    neighbors++;
                if (board[0][j] == 'X') //down
                    neighbors++;
                if (board[i][j - 1] == 'X') //left
                    neighbors++;
                if (board[i + 1][j - 1] == 'X') //up left
                    neighbors++;
                if (board[0][j - 1] == 'X') //down left
                    neighbors++;
                if (board[i][0] == 'X') //right
                    neighbors++;
                if (board[i + 1][0] == 'X') //up right
                    neighbors++;
                if (board[0][0] == 'X') //down right
                    neighbors++;
            }

            //death
            if (board[i][j] == 'X')
            {
                if (neighbors < 2 || neighbors > 3)
                    board[i][j] = ' ';
            }
            //birth
            if (board[i][j] == ' ')
            {
                int r = (rand() % 100) + 1;
                if (neighbors == 3 && r <= percentOrgs)
                    board[i][j] = 'X';
            }
        }
    }
}