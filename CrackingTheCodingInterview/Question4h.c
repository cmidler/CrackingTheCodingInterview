//
//  Question4h.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 You have two very large binary trees: Tl, with millions of nodes, and T2, with
 hundreds of nodes. Create an algorithm to decide ifT2 is a subtree ofTl.
 A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree ofn
 is identical to T2. That is, if you cut off the tree at node n, the two trees would be
 identical.
 */

#include "Question4h.h"



int treeMatch(node_4_h* n1, node_4_h* n2)
{
    if(n2 == NULL)
        return 1;
    if(n1 == NULL)
        return 0;
    
    if(n1->value!=n2->value)
        return 0;
    
    return(treeMatch(n1->left, n2->left) || treeMatch(n1->right, n2->right));
        
}

int traverseTree(node_4_h* n1, node_4_h* n2)
{
    if(n1 == NULL)
        return 0;
    if(n1->value == n2->value && treeMatch(n1, n2))
        return 1;
    return(traverseTree(n1->left, n2) || traverseTree(n1->right, n2));
}

int isMatch(node_4_h* n1, node_4_h* n2)
{
    return traverseTree(n1, n2);
}