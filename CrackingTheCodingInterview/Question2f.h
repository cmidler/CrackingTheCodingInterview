//
//  Question2f.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2f__
#define __CrackingTheCodingInterview__Question2f__

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeF{
    int value;
    struct nodeF* next;
}node_llf;

node_llf* findNodeInLoop(node_llf* head);

#endif /* defined(__CrackingTheCodingInterview__Question2f__) */
