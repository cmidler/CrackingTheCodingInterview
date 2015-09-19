//
//  Question1h.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Assume you have a method isSubstring which checks if one word is a
 substring of another. Given two strings, s1 and s2, write code to check if s2 is
 a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rotation
 of "erbottlewat").
 */

#include "Question1h.h"

bool isSubstring(char*s1, char*s2)
{
    char* pnt = strstr(s1, s2);
    if(pnt)
        return true;
    else
        return false;
}

bool isRotation(char* s1, char*s2)
{
    
    int len = (int) strlen(s1);
    if(len != (int)strlen(s2))
        return false;
    
    char* concat = malloc(sizeof(char)*2*len+1);
    if(!concat) return false;
    
    strcpy(concat, s1);
    strcat(concat, s1);
    
    bool returnType = isSubstring(concat, s2);
    
    free(concat);
    return returnType;
}

