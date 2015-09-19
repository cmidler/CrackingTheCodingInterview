//
//  Question1f.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given an image represented by an NxN matrix, where each pixel in the image is
 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
 place?
 */

#include "Question1f.h"

//simplify first and solve

/*
    2x2  ==>
    1 0     1 1
    1 0     0 0
 
    3x3 ==>
    1 1 0   0 1 1
    1 1 1   0 1 1
    0 0 1   1 1 0
 
    By looking at simple examples can see that the first row becomes the last column, the first column becomes the first row, etc.  Going to assume clockwise
*/


void rotateImageByNinetyDegrees( int** matrix, int n)
{
    
    for (int layer = 0; layer < n / 2; layer++) {
        int last = n - 1 - layer;
        for(int i = layer; i < last; i++) {
            int offset = i - layer;
            // save top
            int top = matrix[layer][i];
            
            // left -> top
            matrix[layer][i] = matrix[last-offset][layer];
            
            // bottom -> left
            matrix[last-offset][layer] = matrix[last][last - offset];
            
            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];
            
            // top -> right
            matrix[i][last] = top;
            }
        }
}