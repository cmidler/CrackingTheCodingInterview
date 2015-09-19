//
//  Question9b.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Imagine a robot sitting on the upper left corner of an X by Y grid. The robot can
 only move in two directions: right and down. How many possible paths are there
 for the robot to go from (0,0) to (X,Y)?
 FOLLOW UP
 Imagine certain spots are "off limits," such that the robot cannot step on them.
 Design an algorithm to find a path for the robot from the top left to the bottom
 right.
 */

#include "Question9b.h"

int isXOffLimits(int x, int y, int** offLimits, int numberOffLimits)
{
    if(offLimits == NULL || numberOffLimits == 0)
        return 1;
    if(x < 1  || y <0)
        return 1;
    
    for(int i = 0; i< numberOffLimits; i++)
    {
        if(offLimits[i][0] == x-1 && offLimits[i][1] == y)
            return 1;
    }
    
    return 0;
}

int isYOffLimits(int x, int y, int** offLimits, int numberOffLimits)
{
    if(offLimits == NULL || numberOffLimits == 0)
        return 1;
    if(x < 0  || y <1)
        return 1;
    
    for(int i = 0; i< numberOffLimits; i++)
    {
        if(offLimits[i][0] == x && offLimits[i][1] == y-1)
            return 1;
        //else printf("%d,%d is not off limits\n", x-1, y-2);
    }
    
    return 0;
}


int possiblePathsForRobotRecursive(int x, int y)
{
    if(x == 0 || y == 0)
        return 0;
    else if(x == 1 || y == 1)
        return 1;
    else
        return possiblePathsForRobotRecursive(x-1, y) + possiblePathsForRobotRecursive(x, y-1);
    
}

int findPathsWithOffLimitsRecursive(int x, int y, int** offLimits, int numberOffLimits)
{
    if(x == 0 || y == 0)
        return 0;
    else if(x == 1 && y == 1)
        return 1;
    else if(isXOffLimits(x-1, y-1, offLimits, numberOffLimits) && isYOffLimits(x-1, y-1, offLimits, numberOffLimits))
        return 0;
    else if(!isXOffLimits(x-1, y-1, offLimits, numberOffLimits) && !isYOffLimits(x-1, y-1, offLimits, numberOffLimits))
            return findPathsWithOffLimitsRecursive(x-1, y, offLimits, numberOffLimits) + findPathsWithOffLimitsRecursive(x, y-1, offLimits, numberOffLimits);
    else if (isXOffLimits(x-1, y-1, offLimits, numberOffLimits) && !isYOffLimits(x-1, y-1, offLimits, numberOffLimits))
        return findPathsWithOffLimitsRecursive(x,y-1, offLimits, numberOffLimits);
    else
        return findPathsWithOffLimitsRecursive(x-1, y, offLimits, numberOffLimits);
    
}

