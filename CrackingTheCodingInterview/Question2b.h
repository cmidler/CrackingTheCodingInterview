//
//  Question2b.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2b__
#define __CrackingTheCodingInterview__Question2b__

#include <stdio.h>
#include <stdlib.h>
typedef struct nodeB{
    int value;
    struct nodeB* next;
}node_llb;

node_llb* findKthToLastElementInList(node_llb* head, int k);
#endif /* defined(__CrackingTheCodingInterview__Question2b__) */
