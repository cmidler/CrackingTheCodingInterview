//
//  Question5c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/9/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given a positive integer, print the next smallest and the next largest number
 that have the same number of 1 bits in their binary representation.
 */

#include "Question5c.h"


int countOneBits(int n)
{
    int oneBits = 0;
    int tmp = n;
    for(int i = 31; i>=0; i--)
    {
        int num = pow(2,i);
        if((tmp-num) >= 0)
        {
            tmp-=num;
            oneBits++;
        }
        if(tmp == 0)
            break;
    }
    
    return oneBits;
}

void printNextBits(int n)
{
    int nOnes = countOneBits(n);
    int higher = n+1;
    int lower = n-1;
    while(higher>0)
    {
        if(countOneBits(higher) == nOnes)
        {
            printf("Higher = %d\n", higher);
            break;
        }
        higher++;
    }
    
    if(higher<=0)
        printf("Error: no higher and positive\n");
    
    
    while(lower>0)
    {
        if(countOneBits(lower) == nOnes)
        {
            printf("Lower = %d\n", lower);
            break;
        }
        lower--;
    }
    
    if(lower<= 0)
        printf("Error: no lower and positive\n");
    
}