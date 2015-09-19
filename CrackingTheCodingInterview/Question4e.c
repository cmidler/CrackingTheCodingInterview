//
//  Question4e.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement a function to check if a binary tree is a binary search tree
 */

#include "Question4e.h"


int checkBST(node_4_e* node, int min, int max)
{
    
    if(node == NULL)
        return 1;
    
    if(node->value < min || node->value >= max)
        return 0;
    
    if(node->left!=NULL)
    {
        int l = checkBST(node->left, min, node->value);
        if(!l)
            return 0;
    }
    
    if(node->right!=NULL)
    {
        int r = checkBST(node->right, node->value, max);
        if(!r)
            return 0;
    }
    
    return 1;
}