//
//  Question11a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 You are given two sorted arrays, A and B, where A has a large enough buffer at the
 end to hold B. Write a method to merge B into A in sorted order.
 */

#include "Question11a.h"

int* mergeAB(int* a, int* b, int aLength, int bLength)
{
    
    int* tmp = malloc(sizeof(int)*aLength);
    if(tmp == NULL)
        return NULL;
    
    for(int i = 0; i<aLength; i++)
        tmp[i] = a[i];
    
    int total = aLength+bLength;
    
    int x = 0;
    int y = 0;
    for(int i = 0; i<total; i++)
    {
        if(x>= aLength)
            a[i] = b[y++];
        else if(y>=bLength)
            a[i] = tmp[x++];
        else
        {
            if(tmp[x]<b[y])
                a[i] = tmp[x++];
            else
                a[i] = b[y++];
        }
            
    }
    free(tmp);
    return a;
}