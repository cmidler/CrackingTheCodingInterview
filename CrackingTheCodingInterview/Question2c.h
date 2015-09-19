//
//  Question2c.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2c__
#define __CrackingTheCodingInterview__Question2c__

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeC{
    int value;
    struct nodeC* next;
}node_llc;

int deleteNodeInMiddle(node_llc* node);
#endif /* defined(__CrackingTheCodingInterview__Question2c__) */
