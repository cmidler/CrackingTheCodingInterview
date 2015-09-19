//
//  Question18a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/9/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write a function that adds two numbers. You should not use + or any arithmetic
 operators.
 */

#include "Question18a.h"

int addTwoNumbers(int a, int b)
{
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return addTwoNumbers(sum, carry); 
    
}