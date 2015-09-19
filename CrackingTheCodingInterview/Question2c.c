//
//  Question2c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement an algorithm to delete a node in the middle of a singly linked list,
 given only access to that node.
 EXAMPLE
 Input: the node c from the linked list a->b->c->d->e
 Result: nothing is returned, but the new linked list looks like a- >b- >d->e
 */

#include "Question2c.h"


//cannot delete last node properly
int deleteNodeInMiddle(node_llc* node)
{
    if(node == NULL || node->next == NULL)
        return 1;
    
    node_llc* ptr = node;
    node_llc* prev = ptr;
    while(ptr!=NULL)
    {
        node_llc* tmp = ptr->next;
        if(tmp != NULL)
        {
            ptr->value = tmp->value;
            prev = ptr;
            ptr = ptr->next;
        }
        else
        {
            prev->next = NULL;
            free(ptr);
            ptr = NULL;
        }
    }
    
    return 0;
}