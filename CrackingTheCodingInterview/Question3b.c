//
//  Question3b.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 How would you design a stack which, in addition to push and pop, also has a
 function min which returns the minimum element? Push, pop and min should
 all operate in O(1) time.
 */

#include "Question3b.h"


stack_b* createStackB()
{
    stack_b* stack = malloc(sizeof(stack_b));
    if(stack == NULL)
        return NULL;
    
    stack->stack = malloc(sizeof(int));
    if(stack->stack == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->minStack = malloc(sizeof(int));
    if(stack->minStack == NULL)
    {
        free(stack);
        free(stack->stack);
        return NULL;
    }
    stack->count = 0;
    stack->max = 1;
    return stack;
}

int pushB(stack_b* stack, int value)
{
    if(stack == NULL)
        return 0;
    
    if(stack->count == stack->max)
    {
        stack->max*=2;
        stack->stack = realloc(stack->stack,sizeof(int)*(stack->max));
        if(stack->stack == NULL)
            return 0;
        stack->minStack = realloc(stack->minStack, sizeof(int)*(stack->max));
        if(stack->minStack == NULL)
            return 0;
    }
    
    
    if(stack->count == 0)
        stack->minStack[stack->count] = value;
    else if(value < stack->minStack[stack->count-1])
        stack->minStack[stack->count] = value;
    else
        stack->minStack[stack->count] = stack->minStack[stack->count-1];
    
    stack->stack[stack->count++] = value;
    return 1;
}

int minB(stack_b* stack)
{
    if(stack == NULL || stack->count == 0)
        return 0;
    
    return stack->minStack[stack->count-1];
}

int popB(stack_b* stack)
{
    if(stack == NULL || stack->count == 0)
        return 0;
    
    stack->count--;
    
    int popVal = stack->stack[stack->count];
    if(stack->count < stack->max && stack->max!=1)
    {
        stack->max/=2;
        stack->stack = realloc(stack->stack,sizeof(int)*(stack->count));
        stack->minStack = realloc(stack->minStack,sizeof(int)*(stack->count));
    }
    
    return popVal;
}

void freeStackB(stack_b* stack)
{
    free(stack->stack);
    free(stack->minStack);
    free(stack);
}