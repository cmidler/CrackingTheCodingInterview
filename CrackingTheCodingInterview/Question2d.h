//
//  Question2d.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2d__
#define __CrackingTheCodingInterview__Question2d__

#include <stdio.h>

typedef struct nodeD{
    int value;
    struct nodeD* next;
}node_lld;

node_lld* partitionLL(node_lld* head, int x);

#endif /* defined(__CrackingTheCodingInterview__Question2d__) */
