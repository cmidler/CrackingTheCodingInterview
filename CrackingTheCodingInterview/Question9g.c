//
//  Question9g.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement the "paint fill" function that one might see on many image editing
 programs. That is, given a screen (represented by a two-dimensional array of
 colors), a point, and a new color, fill in the surrounding area until the color
 changes from the original color.
 */

#include "Question9g.h"


int fillPaint(int**array, int x, int y, int originalColor, int newColor, int xSize, int ySize)
{
    if(x<0 || y<0 || x>=xSize || y >=ySize)
        return 0;
    
    if(array[x][y] == originalColor)
    {
        array[x][y] = newColor;
        if(x>0)
            fillPaint(array, x-1, y, originalColor, newColor, xSize, ySize);
        if(y>0)
            fillPaint(array, x, y-1, originalColor, newColor, xSize, ySize);
        if(y<ySize-1)
            fillPaint(array, x, y+1, originalColor, newColor, xSize, ySize);
        if(x<xSize-1)
            fillPaint(array, x+1, y, originalColor, newColor, xSize, ySize);
    }
    return 1;
}

int paintFill(int** array, int pointX, int pointY, int color, int xSize, int ySize)
{
    int original = array[pointX][pointY];
    return fillPaint(array, pointX, pointY, original, color, xSize, ySize);
}