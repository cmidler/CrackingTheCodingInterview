//
//  Question1b.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated
 string.
 */

#include "Question1b.h"


void reverse(char* str)
{
    int len = (int)strlen(str);
    
    for(int i = 0; i<len/2;i++)
    {
        char tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
    
}