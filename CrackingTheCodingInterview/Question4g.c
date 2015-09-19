//
//  Question4g.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Design an algorithm and write code to find the first common ancestor of two nodes
 in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
 necessarily a binary search tree.
 */

#include "Question4g.h"


int onSide(node_4_g* root, node_4_g* node)
{
    if(node == NULL)
        return 0;
    if(root == node)
        return 1;
    
    return(onSide(root->left, node) || onSide(root->right, node));
}

node_4_g* firstCommonAncestor(node_4_g* root, node_4_g* n1, node_4_g* n2)
{
    if(root == NULL || n1 == NULL || n2 == NULL)
        return NULL;
    
    if(n1 == root || n2 == root)
        return root;
    
    if(n1 == n2)
        return n1;
    
    int isOnLeft1 = onSide(root, n1);
    int isOnLeft2 = onSide(root, n2);
    
    if(isOnLeft1!=isOnLeft2)
        return root;
    
    if(isOnLeft1)
        return firstCommonAncestor(root->left, n1, n2);
    else
        return firstCommonAncestor(root->right, n1, n2);
    
}