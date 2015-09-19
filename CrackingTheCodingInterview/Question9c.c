//
//  Question9c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 A magic index in an array A[0.. .n-1] is defined to be an index such that A[i]
 = i. Given a sorted array of distinct integers, write a method to find a magic
 index, if one exists, in array A.
 FOLLOW UP
 What if the values are not distinct?
 */

#include "Question9c.h"

int findMagicWithDistinct(int* array, int high, int low)
{
    
    if(high<=low || array == NULL)
       return -1;
    
    int mid = (high+low)/2;
    
    if(array[mid] == mid)
        return mid; // found it
    else if(array[mid] > mid)
    {
        return findMagicWithDistinct(array, mid-1, low);
    }
    else
    {
        return findMagicWithDistinct(array, high, mid+1);
    }
    
}


int findMagicWithoutDistinct(int*array, int high, int low)
{
    if(high<=low || array == NULL)
        return -1;
    
    int mid = (high+low)/2;
    
    printf("Mid[%d] is %d, high is %d, low is %d\n", mid,array[mid],high,low);
    int check = 0;
    if(array[mid] == mid)
        return mid; // found it
    
    int newHigh = array[mid];
    if(newHigh<0)
        check = -1;
    else
        check = findMagicWithoutDistinct(array, newHigh, low);
    if(check!= -1)
        return check;
    
    
    printf("checking greater than\n");
    check = findMagicWithoutDistinct(array, high, mid+1);
    
    return check;
}

