//
//  Question3a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#include "Question3a.h"

/*
 Describe how you could use a single array to implement three stacks.
 */

//this can hold more than 3 stacks and is dynamic in nature

stack_a** createStacksOnArrayA(int stackNumber)
{
    
    stack_a** array = malloc(sizeof(int*)*stackNumber);
    if(array == NULL)
        return NULL;
    for(int i = 0; i<stackNumber; i++)
    {
        stack_a* stack = malloc(sizeof(stack_a));
        if(stack == NULL)
        {
            for(int j = 0; j<i; j++)
            {
                if(array[j]!=NULL)
                    free(array[j]->stack);
                free(array[j]);
            }
            free(array);
            return NULL;
        }
        stack->stack = NULL;
        stack->max = 1;
        stack->currentSize = 0;
        array[i] = stack;
    }
    
    return array;
}

int pushA(stack_a** stack, int value, int position)
{
    
    
    if(stack[position]->stack == NULL)
    {
        
        if((stack[position]->stack = malloc(sizeof(int*))) == NULL)
            return 0;
    }
    
    
    
    if(stack[position]->currentSize == stack[position]->max)
    {
        stack[position]->max*=2;
        if((stack[position]->stack = realloc(stack[position]->stack, sizeof(int)*(stack[position]->max)))== NULL)
        {
            stack[position]->max/=2;
            return 0;
        }
    }
    int* sPos = stack[position]->stack;
    
    sPos[stack[position]->currentSize++] = value;
    return 1;
}

int peekA(stack_a** stack, int position)
{
    if(stack[position]->stack == NULL || stack[position]->currentSize == 0)
        return 0;
    return stack[position]->stack[stack[position]->currentSize-1];
}

int popA(stack_a** stack, int position)
{
    stack_a* stackPtr = stack[position];
    if(stackPtr == NULL || stackPtr->currentSize == 0)
        return 0;
    
    stackPtr->currentSize--;
    int returnVal = stackPtr->stack[stackPtr->currentSize];
    if(stackPtr->currentSize < stackPtr->max/2 && stackPtr->max!=1)
    {
        stackPtr->max/=2;
        stack[position]->stack = realloc(stack[position]->stack, sizeof(int)*(stackPtr->currentSize));
    }
    return returnVal;
}

void freeStackA(stack_a** array, int size)
{
    for(int i = 0; i<size; i++)
    {
        if(array[i]!=NULL)
            free(array[i]->stack);
        free(array[i]);
    }
    free(array);
}