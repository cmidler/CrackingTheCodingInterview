//
//  Question9a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 A child is running up a staircase with n steps, and can hop either 1 step, 2 steps,
 or 3 steps at a time. Implement a method to count how many possible ways the
 child can run up the stairs.
 */

#include "Question9a.h"

int childRunSteps(int n)
{
    
    if(n<0)
        return 0;
    else if(n==0)
        return 1;
    else
        return (childRunSteps(n-1) + childRunSteps(n-2) + childRunSteps(n-3));
    
}