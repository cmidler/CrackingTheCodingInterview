//
//  Question4c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given a sorted (increasing order) array with unique integer elements, write an algorithm
 to create a binary search tree with minimal height
 */

#include "Question4c.h"


node_4_c* createBinarySearchTreeC(int* array, int low, int high)
{
    if(high<low)
        return NULL;
    
    int mid = (low+high)/2;
    
    node_4_c* parent = malloc(sizeof(node_4_c));
    parent->value = array[mid];
    parent->left = createBinarySearchTreeC(array, low, mid-1);
    parent->right = createBinarySearchTreeC(array, mid+1, high);
    return parent;
    
}