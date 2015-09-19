//
//  Question4a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/4/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement a function to check if a binary tree is balanced. For the purposes of
 this question, a balanced tree is defined to be a tree such that the heights of the
 two subtrees of any node never differ by more than one.
 */

#include "Question4a.h"


int getHeight(node_4_a* node)
{
    if(node == NULL) return 0;
    
    int leftHeight = getHeight(node->left);
    if(leftHeight == -1)
        return -1;
    int rightHeight = getHeight(node->right);
    if(rightHeight == -1)
        return -1;
    
    int heightDiff = leftHeight-rightHeight;
    
    if(heightDiff > 1 || heightDiff < 1)
        return -1;
    
    if(leftHeight > rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}

int isBalanced(node_4_a* root)
{
    if(getHeight(root) == -1)
        return 0;
    return 1;
}