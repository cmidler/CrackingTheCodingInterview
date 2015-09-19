//
//  Question2a.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2a__
#define __CrackingTheCodingInterview__Question2a__

#include <stdio.h>
#include <stdlib.h>
typedef struct nodeA{
    int data;
    struct nodeA* next;
}node_lla;

int deleteDuplicateNodesWithoutTemporaryBuffer(node_lla* head);
#endif /* defined(__CrackingTheCodingInterview__Question2a__) */
