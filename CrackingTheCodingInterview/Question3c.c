//
//  Question3c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 Therefore, in real life, we would likely start a new stack when the previous stack
 exceeds some threshold. Implement a data structure SetOfStacks that mimics
 this. SetOf Stacks should be composed of several stacks and should create a
 new stack once the previous one exceeds capacity. SetOf Stacks. push() and
 SetOf Stacks. pop() should behave identically to a single stack (that is, pop()
 should return the same values as it would if there were just a single stack).
 FOLLOW UP
 
 Implement a function popAt(int index) which performs a pop operation on
 a specific sub-stack.
 
 */

#include "Question3c.h"

set_of_stacks* createSetOfStacksC(int capacity)
{
    set_of_stacks* set = malloc(sizeof(set_of_stacks));
    if(set == NULL)
        return NULL;
    
    
    set->setOfStacks = malloc(sizeof(stack_c*));
    if(set->setOfStacks == NULL)
    {
        free(set);
        return NULL;
    }
    
    stack_c* stack = malloc(sizeof(stack_c));
    if(stack == NULL)
    {
        free(set->setOfStacks);
        free(set);
        return NULL;
    }
    
    stack->stackArray = malloc(sizeof(int)*capacity);
    if(stack->stackArray == NULL)
    {
        free(stack->stackArray);
        free(set->setOfStacks);
        free(set);
        return NULL;
    }
    
    set->capacity = capacity;
    set->setOfStacks[0] = stack;
    set->itemCount = 0;
    stack->count = 0;
    set->stackCount = 1;
    return set;
    
}

void freeStackC(set_of_stacks*set)
{
    for(int i = 0; i < set->stackCount; i++)
    {
        stack_c* ptr = set->setOfStacks[i];
        free(ptr->stackArray);
        free(ptr);
    }
    free(set->setOfStacks);
    free(set);
}

int pushC(set_of_stacks* set, int value)
{
    if(set == NULL || set->setOfStacks == NULL || set->setOfStacks[0] == NULL)
        return 0;
    
    //get the stack this should be in
    int stackNumber = set->itemCount/set->capacity;;
    
    //see if we need to allocate new memory or not
    if(stackNumber == set->stackCount)
    {
        set->setOfStacks = realloc(set->setOfStacks, sizeof(stack_c*)*(++set->stackCount));
        if(set->setOfStacks == NULL)
            return 0;
        
        stack_c* newStack = malloc(sizeof(stack_c));
        if(newStack == NULL)
            return 0;
        newStack->stackArray = malloc(sizeof(int)*(set->capacity));
        if(newStack->stackArray == NULL)
        {
            free(newStack);
            return 0;
        }
        newStack->count = 0;
        
        set->setOfStacks[stackNumber] = newStack;
    }
    
    
    set->setOfStacks[stackNumber]->stackArray[set->setOfStacks[stackNumber]->count++] = value;
    set->itemCount++;
    
    return 1;
}

int popC(set_of_stacks* set)
{
    if(set == NULL || set->setOfStacks == NULL || set->setOfStacks[0] == NULL)
        return 0;
    //get the stack this should be in
    int stackNumber = (--set->itemCount)/set->capacity;
    
    
    int returnVal = set->setOfStacks[stackNumber]->stackArray[(--set->setOfStacks[stackNumber]->count)];
    if(set->setOfStacks[stackNumber]->count == 0 && set->itemCount!=0)
    {
        free(set->setOfStacks[stackNumber]->stackArray);
        free(set->setOfStacks[stackNumber]);
        set->setOfStacks = realloc(set->setOfStacks, sizeof(stack_c*)*(--set->stackCount));
    }
    
    return returnVal;
}

int popAt(set_of_stacks* set, int index)
{
    if(set == NULL || set->setOfStacks == NULL || set->setOfStacks[index] == NULL)
        return 0;
    
    if(index>= set->stackCount)
        return 0;
    
    int returnVal = set->setOfStacks[index]->stackArray[(--set->setOfStacks[index]->count)];
    
    if(!set->setOfStacks[index]->count && set->itemCount!=0)
    {
        int i = index;
        for(; i<set->stackCount-1; i++)
        {
            set->setOfStacks[i]->count = set->setOfStacks[i+1]->count;
            for(int j = 0; j<set->setOfStacks[i]->count; j++)
                set->setOfStacks[i]->stackArray[j] = set->setOfStacks[i+1]->stackArray[j];
        }
        
        free(set->setOfStacks[i]->stackArray);
        free(set->setOfStacks[i]);
        set->setOfStacks[i] = NULL;
        set->setOfStacks = realloc(set->setOfStacks, sizeof(stack_c*)*(--set->stackCount));
        
    }
    
    set->itemCount--;
    
    return returnVal;
}

