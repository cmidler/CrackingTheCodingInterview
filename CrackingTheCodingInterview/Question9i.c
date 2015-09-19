//
//  Question9i.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write an algorithm to print all ways of arranging eight queens on an 8x8 chess
 board so that none of them share the same row, column or diagonal. In this case,
 "diagonal" means all diagonals, not just the two that bisect the board
 */

#include "Question9i.h"

int checkValid(int* columns, int row1, int column1)
{
    for (int row2 = 0; row2 < row1; row2++)
    {
        int column2 = columns[row2];
        /* Check if (row2, column2) invalidates (row1, column1) as a
         * queen spot. */
        
        /* Check if rows have a queen in the same column */
        if (column1 == column2)
            return 0;
        
        /* Check diagonals: if the distance between the columns
         * equals the distance between the rows, then they're in the
         * same diagonal. */
        int columnDistance = abs(column2 - column1);
        
        /* rowl > row2, so no need for abs */
        int rowDistance = row1 - row2;
        if (columnDistance == rowDistance)
            return 0;
    }
    return 1;
}

void arrangeQueens(int n, int row, int* column, int* solutions)
{
    if (row == n) // Found valid placement
    {
        printf("\n%d Queen Solution Found:\n", ++(*solutions));
        for(int i = 0; i<n; i++)
            printf("Queen at row %d and column %d\n", i,column[i]);
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            if (checkValid(column, row, col))
            {
                column[row] = col; // Place queen
                arrangeQueens(n, row + 1, column, solutions);
            }
        }
    }
}

