//
//  Question4f.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write an algorithm to find the 'next'node (i.e., in-order successor) of a given node in
 a binary search tree. You may assume that each node has a link to its parent
 */

#include "Question4f.h"

node_4_f* findNextNode(node_4_f* node)
{
    
    node_4_f* ptr = node;
    if(ptr->right!=NULL)
    {
        ptr = ptr->right;
        while(ptr->left!=NULL)
            ptr = ptr->left;
        return ptr;
    }
    else
    {
        while(ptr->parent!=NULL)
        {
            ptr = ptr->parent;
            if(ptr->value >= node->value)
            {
                if(ptr->right == NULL)
                    return ptr;
                
                ptr = ptr->right;
                while(ptr!=NULL)
                    ptr = ptr->left;
                return ptr;
            }
        }
    }
    
    
    return NULL;
}