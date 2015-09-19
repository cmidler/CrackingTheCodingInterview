//
//  Question2b.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement an algorithm to find the kth to last element of a singly linked list
 */




#include "Question2b.h"

node_llb* findKthToLastElementInList(node_llb* head, int k)
{
    if(k<= 0) return NULL;
    node_llb* ptr = head;
    node_llb* tracker = NULL;
    int nodeNumber = 1;
    while (ptr!=NULL)
    {
        if(nodeNumber == k) tracker = head;
        if(tracker!= NULL && ptr->next!=NULL)
            tracker = tracker->next;
        ptr = ptr->next;
        nodeNumber++;
    }
    return tracker;
}
