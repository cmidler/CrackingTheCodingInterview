//
//  Question4f.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question4f__
#define __CrackingTheCodingInterview__Question4f__

#include <stdio.h>


typedef struct node4F{
    struct node4F* parent;
    struct node4F* left;
    struct node4F* right;
    int value;
}node_4_f;

#endif /* defined(__CrackingTheCodingInterview__Question4f__) */
