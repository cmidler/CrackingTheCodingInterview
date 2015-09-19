//
//  Question3b.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question3b__
#define __CrackingTheCodingInterview__Question3b__

#include <stdio.h>
#include <stdlib.h>

typedef struct stackB{
    int count;
    int max;
    int* stack;
    int* minStack;
}stack_b;

stack_b* createStackB();
int pushB(stack_b* stack, int value);
int minB(stack_b* stack);
int popB(stack_b* stack);
void freeStackB(stack_b* stack);
#endif /* defined(__CrackingTheCodingInterview__Question3b__) */
