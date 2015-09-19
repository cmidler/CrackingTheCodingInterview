//
//  Question11f.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given an M x N matrix in which each row and each column is sorted in ascending
 order, write a method to find an element.
 */

#include "Question11f.h"




int* findElementInMatrix(int** array, int m, int n, int element)
{
    
    if(n<0 || m<0 || array == NULL)
        return NULL;
    
    
    int* returnVal = malloc(sizeof(int)*2);
    if(returnVal == NULL)
        return NULL;
    
    
    int row = 0;
    int col = n-1;
    
    while(1)
    {
        
        if(array[row][col] == element)
        {
            returnVal[0] = row;
            returnVal[1] = col;
            return returnVal;
        }
        else if(array[row][col]>element)
        {
            col--;
            if(col < 0)
                break;
        }
        else
        {
            row++;
            if(row>=m)
                break;
        }
    }
    
    
    free(returnVal);
    return NULL;
}