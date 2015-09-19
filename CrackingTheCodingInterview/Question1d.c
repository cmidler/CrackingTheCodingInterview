//
//  Question1d.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//


/*
 Write a method to replace all spaces in a string with'%20'. You may assume that
 the string has sufficient space at the end of the string to hold the additional
 characters, and that you are given the "true" length of the string. (Note: if implementing
 in Java, please use a character array so that you can perform this operation
 in place.)
 EXAMPLE
 Input: "Mr John Smith    "
 Output: "Mr%20John%20Smith"
 */

#include "Question1d.h"

void replaceAllSpacesInString(char* str)
{
    int len = (int) strlen(str);
    
    if(!len) return;
    
    char tmpStr[len+1]; 
    strncpy(tmpStr, str, len);
    int tmpLoc = 0;
    for(int i  = 0; i<len; i++)
    {
        if(tmpStr[i]!=' ')
            str[tmpLoc++] = tmpStr[i];
        else
        {
            str[tmpLoc++] = '%';
            str[tmpLoc++] = '2';
            str[tmpLoc++] = '0';
        }
    }
    
    str[tmpLoc] = '\0';
    
    
}