//
//  Question3a.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question3a__
#define __CrackingTheCodingInterview__Question3a__

#include <stdio.h>
#include <stdlib.h>

typedef struct stackA{
    int max;
    int currentSize;
    int* stack;
}stack_a;

stack_a** createStacksOnArrayA(int stackNumber);
int pushA(stack_a** stack, int value, int position);
int peekA(stack_a** stack, int position);
int popA(stack_a** stack, int position);
void freeStackA(stack_a** array, int size);

#endif /* defined(__CrackingTheCodingInterview__Question3a__) */
