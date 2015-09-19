//
//  Question3f.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question3f__
#define __CrackingTheCodingInterview__Question3f__

#include <stdio.h>
#include <stdlib.h>

typedef struct stackF{
    int max;
    int current;
    int* values;
    
}stack_f;


int peekF(stack_f* stack);
int isEmptyF(stack_f* stack);
int popF(stack_f* stack);
int pushF(stack_f* stack, int value);

#endif /* defined(__CrackingTheCodingInterview__Question3f__) */
