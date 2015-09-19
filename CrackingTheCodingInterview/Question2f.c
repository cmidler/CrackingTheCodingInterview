//
//  Question2f.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/27/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//


/*
 Given a circular linked list, implement an algorithm which returns the node at
 the beginning of the loop.
 DEFINITION
 Circular linked list: A (corrupt) linked list in which a node's next pointer points
 to an earlier node, so as to make a loop in the linked list.
 EXAMPLE
 Input: A ->B->C->D->E- > C [the same C as earlier]
 Output: C
 */


//slow runner, fast runner algorithm is a better solution since it doesn't use O(n) space
//but this is the solution that came to me first

#include "Question2f.h"

typedef struct nodeFF{
    struct nodeFF* next;
    node_llf* node;
}node_llff;

typedef struct hashF{
    int size;
    node_llff** table;
}hash_llf;

//initialize hash table

hash_llf* createTable(int size)
{
    
    hash_llf* hashTable = malloc(sizeof(hash_llf));
    if(hashTable == NULL) return NULL;
    
    hashTable->size = size;
    hashTable->table = malloc(sizeof(node_llff*)*size);
    for(int i = 0; i<size; i++)
    {
        (hashTable->table)[i] = NULL;
    }
    
    return hashTable;
}

void freeTable(hash_llf* table)
{
    int size = table->size;
    for(int i =0; i <size; i++)
    {
        node_llff* ptr = (table->table)[i];
        while(ptr!= NULL)
        {
            node_llff* tmp = ptr->next;
            free(ptr);
            ptr = tmp;
        }
    }
    free(table);
}

unsigned int hash(unsigned int key)
{
    unsigned hashValue = (key*82739287)%(2^32);
    return hashValue;
}


int addToHashTable(hash_llf* table, node_llf* value)
{
    int size = table->size;
    int index = (hash((unsigned int)value))%size;
    
    node_llff* node = malloc(sizeof(node_llff));
    if(node == NULL)
        return 0;
    
    node->node = value;
    
    if(table->table[index] == NULL)
        node->next = NULL;
    else
        node->next = table->table[index];
    table->table[index] = node;
    
    return 1;
}

int inHashTable(hash_llf* table, node_llf* key)
{
    int size = table->size;
    int index = hash((unsigned int)key)%size;
    
    node_llff* ptr = table->table[index];
    while(ptr!=NULL)
    {
        if(ptr->node == key)
            return 1;
        ptr = ptr->next;
    }
    
    return 0;
}

node_llf* findNodeInLoop(node_llf* head)
{
    hash_llf* table = createTable(10);//so we have collisions for testing
    if(table == NULL)
        return NULL;
    
    node_llf* ptr = head;
    int i = 0;
    
    while(ptr!=NULL)
    {
        if(inHashTable(table, ptr))
        {
            freeTable(table);
            return ptr;
        }
        else
            addToHashTable(table, ptr);
        ptr = ptr->next;
        i++;
    }
    return NULL;
}





