//
//  Question1.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.



//  Implement an algorithm to determine if a string has all unique characters. What
//  if you cannot use additional data structures?

#include "Question1.h"

//only considering ascii characters and assuming a == A
bool allUniqueChars(char* string)
{
    int len = (int)strlen(string);
    if(len <=1)
        return true;
    
    
    char check[32];
    
    memset(check,0,32);
    
    
    for(int i =0; i < len; i++)
    {
        char c = string[i];
        int index = 0;
        if(c>='0' && c<='9')
            index = 25+c-'0';
        else if (c>='A' && c<='Z')
            index = c-'A';
        else if (c>='a' && c<='z')
            index = c-'a';
        else
            return false;
        
        if(check[index]==1)
            return false;
        else
            check[index] = 1;
    }
    
    
    return true;
}