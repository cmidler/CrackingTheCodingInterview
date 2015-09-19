//
//  Question2e.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question2e__
#define __CrackingTheCodingInterview__Question2e__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodeE{
    int value;
    struct nodeE* next;
}node_lle;

node_lle* addReverseOrderLL(node_lle* first, node_lle* second);
node_lle* addForwardOrderLL(node_lle* first, node_lle* second);
#endif /* defined(__CrackingTheCodingInterview__Question2e__) */
