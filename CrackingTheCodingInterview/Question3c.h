//
//  Question3c.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question3c__
#define __CrackingTheCodingInterview__Question3c__

#include <stdio.h>
#include <stdlib.h>

typedef struct stackC{
    int count;
    int* stackArray;
}stack_c;

typedef struct setOfStacks{
    stack_c** setOfStacks;
    int capacity;
    int itemCount;
    int stackCount;
}set_of_stacks;

set_of_stacks* createSetOfStacksC(int capacity);
void freeStackC(set_of_stacks*set);
int pushC(set_of_stacks* set, int value);
int popC(set_of_stacks* set);
int popAt(set_of_stacks* set, int index);
#endif /* defined(__CrackingTheCodingInterview__Question3c__) */
