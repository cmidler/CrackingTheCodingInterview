//
//  Question2e.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 You have two numbers represented by a linked list, where each node contains a
 single digit. The digits are stored in reverse order, such that the 1s digit is at the
 head of the list. Write a function that adds the two numbers and returns the sum
 as a linked list.
 EXAMPLE
 Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
 Output: 2 -> 1 -> 9.That is, 912.
 FOLLOW UP
 Suppose the digits are stored in forward order. Repeat the above problem.
 EXAMPLE
 Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295.
 Output: 9 -> 1 -> 2.That is, 912.
 */

#include "Question2e.h"

int concatValuesLL(node_lle* node)
{
    node_lle* ptr = node;
    
    int i = 1;
    int total = 0;
    while(ptr!=NULL)
    {
        total+= (ptr->value)*i;
        i*=10;
        ptr = ptr->next;
    }
    
    return total;
    
}

int concatValuesReverseLL(node_lle* node)
{
    node_lle* ptr = node;
    
    int i = 0;
    int total = 0;
    int array[10];
    while(ptr!=NULL)
    {
        array[i] = ptr->value;
        ptr = ptr->next;
        i++;
    }
    
    i--;
    
    int multiplier = 1;
    for(; i>=0; i--)
    {
        total+= (array[i])*multiplier;
        multiplier*=10;
    }
    
    return total;
    
}



node_lle* addReverseOrderLL(node_lle* first, node_lle* second)
{
    int val1 = concatValuesLL(first);
    int val2 = concatValuesLL(second);
    
    int total = val1+val2;
    
    node_lle* head = NULL;
    node_lle* ptr = NULL;
    while(total)
    {
        node_lle* newNode = malloc(sizeof(node_lle));
        
        //free
        if(newNode == NULL)
        {
            while(head!=NULL)
            {
                node_lle* tmp = head;
                head = head->next;
                free(tmp);
                tmp = NULL;
            }
        }
        
        newNode->value = total%10;
        newNode->next = NULL;
        if(head == NULL)
        {
            head = ptr = newNode;
        }
        else
        {
            ptr->next = newNode;
            ptr = ptr->next;
        }
        
        total/=10;
    }
    
    return head;
}

node_lle* addForwardOrderLL(node_lle* first, node_lle* second)
{
    int val1 = concatValuesReverseLL(first);
    int val2 = concatValuesReverseLL(second);
    
    int total = val1+val2;
    
    node_lle* ptr = NULL;
    while(total)
    {
        node_lle* newNode = malloc(sizeof(node_lle));
        
        //free
        if(newNode == NULL)
        {
            while(ptr!=NULL)
            {
                node_lle* tmp = ptr;
                ptr = ptr->next;
                free(tmp);
                tmp = NULL;
            }
        }
        
        newNode->value = total%10;
        newNode->next = ptr;
        ptr = newNode;
        
        total/=10;
    }
    
   
    
    return ptr;
}

