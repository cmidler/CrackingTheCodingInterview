//
//  Question4a.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/4/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question4a__
#define __CrackingTheCodingInterview__Question4a__

#include <stdio.h>
#include <stdlib.h>


typedef struct node4A{
    struct node4A* left;
    struct node4A* right;
    struct node4A* parent;
    int value;
}node_4_a;


#endif /* defined(__CrackingTheCodingInterview__Question4a__) */
