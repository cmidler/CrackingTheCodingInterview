//
//  Question9d.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write a method to return all subsets of a set.
 */

#include "Question9d.h"


//The book solution does a recursive solution, but I optimized it to be iterative.

void freeSets(sets_d* sets)
{
    for(int i = 0; i < sets->max; i++)
    {
        free(sets->sets[i]->set);
        free(sets->sets[i]);
    }
    free(sets->sets);
    free(sets);
}

sets_d* allSubsetOfSet(int*set, int n)
{
    if(n <= 0 || set == NULL)
        return NULL;
    sets_d* sets = malloc(sizeof(sets_d));
    if(sets == NULL)
        return NULL;
    set_d** allSets = malloc(sizeof(set_d*)*n);
    if(allSets == NULL)
    {
        free(sets);
        return NULL;
    }
    
    set_d* s = malloc(sizeof(set_d));
    if(s == NULL)
    {
        free(allSets);
        free(sets);
        return NULL;
    }
    
    sets->numberOfSets = 1;
    sets->sets = allSets;
    sets->max = n;
    sets->sets[0] = s;
    
    int* newSet = NULL;
    sets->sets[0]->set = newSet;
    sets->sets[0]->size = 0;
    
    for(int i = 1; i<n; i++)
    {
        int j = 0;
        for(; j<sets->numberOfSets;j++)
        {
            if(sets->numberOfSets+j == sets->max)
            {
                sets->max*=2;
                sets->sets = realloc(sets->sets, sizeof(set_d*)*(sets->max));
                if(sets->sets == NULL)
                {
                    sets->max/=2;
                    freeSets(sets);
                }
            }
            
            s = malloc(sizeof(set_d));
            if(s == NULL)
            {
                freeSets(sets);
                return NULL;
            }
            
            newSet = malloc(sizeof(int)*(sets->sets[j]->size+1));
            if(newSet == NULL)
            {
                freeSets(sets);
                free(s);
                return NULL;
            }
            
            sets->sets[sets->numberOfSets+j] = s;
            s->size = sets->sets[j]->size;
            s->set = newSet;
            int k = 0;
            for(; k<s->size; k++)
                s->set[k] = sets->sets[j]->set[k];
            s->set[k] = i;
            s->size++;
            
        }
        
        sets->numberOfSets+=j;
        
    }
    
    sets->sets = realloc(sets->sets,sizeof(set_d*)*(sets->numberOfSets));
    if(sets->sets == NULL)
        return NULL;
    
    sets->max = sets->numberOfSets;
    
    return sets;
}
