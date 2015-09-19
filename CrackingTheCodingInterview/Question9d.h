//
//  Question9d.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question9d__
#define __CrackingTheCodingInterview__Question9d__

#include <stdio.h>
#include <stdlib.h>

typedef struct setD{
    int* set;
    int size;
}set_d;


typedef struct setsD{
    set_d** sets;
    int numberOfSets;
    int max;
}sets_d;

void freeSets(sets_d* sets);
sets_d* allSubsetOfSet(int*set, int n);
#endif /* defined(__CrackingTheCodingInterview__Question9d__) */
