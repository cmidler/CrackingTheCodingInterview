//
//  Question9h.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5
 cents) and pennies (1 cent), write code to calculate the number of ways of representing
 n cents.
 */

#include "Question9h.h"


int makeChange(int centsLeft, int denom)
{
    
    int next_denom = 0;
    switch (denom) {
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
        case 1:
            return 1;
    }
    
    int ways = 0;
    for (int i = 0; i * denom <= centsLeft; i++)
    {
            ways += makeChange(centsLeft - i * denom, next_denom);
    }
    return ways;
}

int calculateCents(int n)
{
    return makeChange(n,25);
}