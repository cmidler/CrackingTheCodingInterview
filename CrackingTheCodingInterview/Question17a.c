//
//  Question17a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/9/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write a function to swap a number in place (that is, without temporary variables).
 */

#include "Question17a.h"

void swap17A(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
