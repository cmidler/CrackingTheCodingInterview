//
//  Question3f.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write a program to sort a stack in ascending order (with biggest items on top).
 You may use at most one additional stack to hold items, but you may not copy
 the elements into any other data structure (such as an array). The stack supports
 the following operations: push, pop, peek, and isEmpty.
 */

#include "Question3f.h"


int peekF(stack_f* stack)
{
    int returnVal = -1;
    if(stack->current)
        returnVal = stack->values[stack->current-1];
    
    //printf("return value for peek is %d\n", returnVal);
    
    return returnVal;
}

int isEmptyF(stack_f* stack)
{
    if(stack->current)
        return 0;
    return 1;
}

int popF(stack_f* stack)
{
    if(isEmptyF(stack))
        return -1;
    
    int returnVal = stack->values[--stack->current];
    if(stack->current>0 && stack->current <= stack->max/2)
    {
        stack->max = stack->current;
        stack->values = realloc(stack->values, sizeof(int)*(stack->current));
        if(stack->values == NULL)
            return -1;
    }
    
    //printf("popping %d off of stack\n", returnVal);
    
    return returnVal;
}

void pushOtherStack(stack_f* tmp, int value)
{
    printf("Pushing %d onto tmp stack at index %d\n", value, tmp->current);
    tmp->values[tmp->current++] = value;
}

int pushF(stack_f* stack, int value)
{
    
    //see if we need more memory
    if(stack->current == stack->max)
    {
        stack->max*=2;
        stack->values = realloc(stack->values, sizeof(int)*(stack->max));
        if(stack->values == NULL)
            return -1;
    }
    
    
    if(isEmptyF(stack) || peekF(stack) <=value)
    {
        stack->values[stack->current++] = value;
    }
    else
    {
        printf("\n");
        stack_f* tmpStack = malloc(sizeof(stack_f));
        if(tmpStack == NULL)
            return -1;
        
        int* tmpValues = (int*)malloc(sizeof(int)*(stack->max));
        if(tmpValues == NULL)
        {
            free(tmpStack);
            return -1;
        }
        
        tmpStack->values = tmpValues;
        tmpStack->current = 0;
        tmpStack->max = stack->max;
        while(!isEmptyF(stack))
        {
            if(peekF(stack)<value)
                break;
            pushOtherStack(tmpStack, popF(stack));
        }
        
        pushF(stack, value);
        
        while(!isEmptyF(tmpStack))
            pushF(stack, popF(tmpStack));
        free(tmpStack->values);
        free(tmpStack);
    }
    return 1;
}
