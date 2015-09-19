//
//  Question2a.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write code to remove duplicates from an unsorted linked list.
 FOLLOW UP
 How would you solve this problem if a temporary buffer is not allowed?
 */

#include "Question2a.h"




//making assumption of singley linked list for this problem

int deleteDuplicateNodesWithoutTemporaryBuffer(node_lla* head)
{
    node_lla* ptr;
    node_lla* tmp = head;
    while(tmp!=NULL)
    {
        node_lla* prev = tmp;
        ptr = tmp->next;
        while(ptr!=NULL)
        {
            if(ptr->data == tmp->data)
            {
                prev->next = ptr->next;
                ptr->next = NULL;
                free(ptr);
                ptr = prev->next;
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
            
            
        }
        tmp = tmp->next;
    }
    
    return 0;
}