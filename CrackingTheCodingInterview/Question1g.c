//
//  Question1g.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write an algorithm such that if an element in an MxN matrix is 0, its entire row
 and column are set to 0.
 */

#include "Question1g.h"


int setMXNMatrixRowAndColumnToZero(int** matrix, int m, int n)
{
    int* zeroRows = malloc(sizeof(int)*m);
    int* zeroCols = malloc(sizeof(int)*n);
    
    if(!zeroRows || !zeroCols)
        return -1;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(!matrix[i][j])
            {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
                break;
            }
        }
    }
    
    int bigger = m;
    if(n>m) bigger = n;
    for(int i =0; i<bigger; i++)
    {
        if(i<m && zeroRows[i])
        {
            for(int j =0; j< n; j++)
            {
                matrix[i][j] = 0;
            }
        }
        
        if(i<n && zeroCols[i])
        {
            for(int j = 0; j<m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    
    free(zeroCols);
    free(zeroRows);
    
    return 1;
}