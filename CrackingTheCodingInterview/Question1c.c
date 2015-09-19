//
//  Question1c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//


/*
 Given two strings, write a method to decide if one is a permutation of the other.
 */



#include "Question1c.h"


void countCharsForString(char* str, int*check)
{
    int len = (int) strlen(str);
    for(int i = 0; i < len; i++)
    {
        char c = str[i];
        check[c]++;
    }
}

//O(n) solution, assuming only ascii

bool isPermutationOfString(char* str1, char*str2)
{
    if(strlen(str1) != strlen(str2))
        return false;
    
    int* check1 = calloc(128,sizeof(int));
    int* check2 = calloc(128,sizeof(int));
    
    //calloc fail
    if(!check1 || !check2)
        return false;
    
    countCharsForString(str1, check1);
    countCharsForString(str2, check2);
    
    for(int i = 0; i < 128; i++)
    {
        if(check1[i]!=check2[i])
        {
            free(check1);
            free(check2);
            return false;
        }
    }
    
    free(check1);
    free(check2);
    return true;
}




