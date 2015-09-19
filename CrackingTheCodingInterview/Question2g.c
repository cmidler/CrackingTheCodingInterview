//
//  Question2g.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
  Implement a function to check if a linked list is a palindrome.
 */

#include "Question2g.h"

int compareArray(int* array, int length)
{
    if(length<1)
        return 0;
    
    for(int i = 0; i <length/2; i++)
    {
        if(array[i] != array[length-i-1])
            return 0;
    }
    
    return 1;
}

int isLLPalindrome(node_llg* head)
{
    node_llg* ptr = head;
    
    int* store = malloc(sizeof(int)*1);
    if(store == NULL)
        return 0;
    
    int count = 0;
    int max = 1;
    
    while(ptr!=NULL)
    {
        if(count == max)
        {
            max*=2;
            if((store = realloc(store, sizeof(int)*max)) == NULL)
                return 0;
        }
        store[count++] = ptr->value;
        ptr = ptr->next;
    }
    
    int isPal = compareArray(store, count);
    
    free(store);
    return isPal;
}

