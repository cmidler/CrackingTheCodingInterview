//
//  Question9f.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement an algorithm to print all valid (e.g., properly opened and closed)
 combinations of n-pairs of parentheses.
 EXAMPLE
 Input: 3
 Output: ((())), (()()), (())(), ()(()), ()()()
 */

#include "Question9f.h"


void parenFun(char* str,int left, int right, int current)
{
    if(str == NULL)
        return;
    
    if(left<0 || right < 0)
        return;
    if(left == 0 && right == 0)
    {
        printf("%s\n", str);
        return;
    }
    
    if(left>0)
    {
        str[current] ='(';
        parenFun(str, left-1, right, current+1);
    }
    
    if(right>left)
    {
        str[current] = ')';
        parenFun(str, left, right-1, current+1);
    }
    
}

void printParens(int n)
{
    char* parens = malloc(sizeof(char)*n+1);
    if(parens == NULL)
        return;
    parenFun(parens,n,n,0);
}