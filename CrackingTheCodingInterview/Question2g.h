//
//  Question2g.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/31/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2g__
#define __CrackingTheCodingInterview__Question2g__

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeG{
    int value;
    struct nodeG* next;
}node_llg;

int isLLPalindrome(node_llg* head);

#endif /* defined(__CrackingTheCodingInterview__Question2g__) */
