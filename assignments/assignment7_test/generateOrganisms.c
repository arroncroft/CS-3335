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
            neighbors = 0;
            if ((i != 0) && (i != a-1) && (j != 0) && (j != b-1))
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
            if (i == 0 && j != 0 && j != b-1) //top row
            {
            	if(board[a-1][j] == 'X') //up
            		neighbors++;
            	if (board[i - 1][j] == 'X') //down
	                neighbors++;
	            if (board[i][j - 1] == 'X') //left
	                neighbors++;
	            if(board[a-1][j-1] == 'X') //up left
            		neighbors++;
           		if (board[i - 1][j - 1] == 'X') //down left
	                neighbors++;
	            if (board[i][j + 1] == 'X') //right
	                neighbors++;
            	if(board[a-1][j+1] == 'X') //up right
            		neighbors++;
            	if (board[i - 1][j + 1] == 'X') //down right
	                neighbors++;
            }
            if (i == a-1 && j != 0 && j != b-1) //bottom row
            {
            	if(board[0][j] == 'X') //down
            		neighbors++;
            	if(board[0][j-1] == 'X') //down left
            		neighbors++;
            	if(board[0][j+1] == 'X') //down right
            		neighbors++;
            }
            if (j == 0) //left column
            {
            	
            }
            if (j == b-1) //right column
            {
            	
            }
            if(board[i][j] == ' ')
				board[i][j] = neighbors + '0'; //test line
			/*
            //death
            if (board[i][j] == 'X')
            {
                if (neighbors != 2 && neighbors != 3)
                    board[i][j] == ' ';
            }
            //birth
            else if (board[i][j] == ' ')
            {   
                int r = (rand() % 100) + 1;
                if (neighbors == 3 && r <= percentOrgs)
                    board[i][j] = 'X';
            }
            */
        }
    }
}