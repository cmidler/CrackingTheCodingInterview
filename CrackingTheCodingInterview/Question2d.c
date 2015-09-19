//
//  Question2d.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write code to partition a linked list around a value x, such that all nodes less than
 x come before all nodes greater than or equal to x.
 */

#include "Question2d.h"

node_lld* partitionLL(node_lld* head, int x)
{
    
    node_lld* lowNode = NULL;
    node_lld* highNode = NULL;
    node_lld* highHead = NULL;
    node_lld* xNode = NULL;
    node_lld* xHead = NULL;
    node_lld* lowHead = NULL;
    node_lld* ptr = head;
    
    while(ptr!=NULL)
    {
        if(ptr->value == x)
        {
            if(xHead == NULL)
            {
                xHead = ptr;
                xNode = xHead;
            }
            else
            {
                xNode->next = ptr;
                xNode = ptr;
            }
            
        }
        else if(ptr->value < x)
        {
            if(lowHead == NULL)
            {
                lowHead = ptr;
                lowNode = lowHead;
            }
            else
            {
                lowNode->next = ptr;
                lowNode = ptr;
            }
            
            
        }
        else
        {
            if(highHead == NULL)
            {
                highHead = ptr;
                highNode = highHead;
            }
            else
            {
                highNode->next = ptr;
                highNode = ptr;
            }
        }
        
        ptr = ptr->next;
    }
    
    if(highNode !=NULL)
        highNode->next = NULL;
    
    if(highHead!=NULL)
    {
        if(xNode!=NULL)
        {
            xNode->next = highHead;
        }
        else
        {
            xHead = xNode = highHead;
        }
    }
    
    
    if(lowNode!=NULL)
    {
        lowNode->next = xHead;
    }
    else
    {
        lowHead = xHead;
    }
    
    
    
    return lowHead;
}