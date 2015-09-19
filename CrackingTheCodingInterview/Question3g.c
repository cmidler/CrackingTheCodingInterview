//
//  Question3g.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/4/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 An animal shelter holds only dogs and cats, and operates on a strictly "first in,
 first out" basis. People must adopt either the "oldest" (based on arrival time) of
 all animals at the shelter, or they can select whether they would prefer a dog or
 a cat (and will receive the oldest animal of that type). They cannot select which
 specific animal they would like. Create the data structures to maintain this system
 and implement operations such as enqueue, dequeueAny, dequeueDog and
 dequeueCat.You may use the built-in LinkedList data structure.
 */

#include "Question3g.h"


node_3_g* dequeueDog(queue_3_g* queue)
{
    node_3_g* returnPtr = queue->headDog;
    if(returnPtr == NULL)
        return NULL;
    
    node_3_g* dogPtr = returnPtr;
    queue->headDog = dogPtr->next;
    if(queue->headDog == NULL)
        queue->lastDog = NULL;
    
    while(dogPtr!= NULL)
    {
        dogPtr->order--;
        dogPtr = dogPtr->next;
    }
    
    node_3_g* catPtr = queue->headCat;
    while(catPtr!=NULL)
    {
        catPtr->order--;
        catPtr = catPtr->next;
    }
    
    return returnPtr;
}

node_3_g* dequeueCat(queue_3_g* queue)
{
    
    node_3_g* returnPtr = queue->headCat;
    if(returnPtr == NULL)
        return NULL;
    
    node_3_g* catPtr = returnPtr;
    queue->headCat = catPtr->next;
    if(queue->headCat == NULL)
        queue->lastCat = NULL;
    
    while(catPtr!= NULL)
    {
        catPtr->order--;
        catPtr = catPtr->next;
    }
    
    node_3_g* dogPtr = queue->headDog;
    while(dogPtr!=NULL)
    {
        dogPtr->order--;
        dogPtr = dogPtr->next;
    }
    
    
    
    
    return returnPtr;
}


node_3_g* dequeueAny(queue_3_g* queue)
{
    if(queue->headDog == NULL && queue->headCat == NULL)
        return NULL;
    
    if(queue->headDog == NULL)
        return dequeueDog(queue);
    else if(queue->headCat == NULL)
        return dequeueCat(queue);
    
    node_3_g* dogPtr = queue->headDog;
    node_3_g* catPtr = queue->headCat;
    node_3_g* returnPtr = dogPtr;
    if(dogPtr->order>catPtr->order)
    {
        returnPtr = catPtr;
        queue->headCat = catPtr->next;
        if(queue->headCat == NULL)
            queue->lastCat = NULL;
    }
    else
    {
        queue->headDog = dogPtr->next;
        if(queue->headDog == NULL)
            queue->lastDog = NULL;
    }
    
    while(dogPtr!=NULL)
    {
        dogPtr->order--;
        dogPtr = dogPtr->next;
    }
    
    while(catPtr!=NULL)
    {
        catPtr->order--;
        catPtr = catPtr->next;
    }
    
    
    return returnPtr;
}


int enqueue(queue_3_g* queue, int isDog)
{
    node_3_g* newNode = malloc(sizeof(node_3_g));
    if(newNode == NULL)
        return -1;
    
    newNode->next = NULL;
    newNode->order = queue->total++;;
    newNode->isDog = isDog;
    if(isDog)
    {
        if (queue->lastDog!=NULL)
        {
            queue->lastDog->next = newNode;
            queue->lastDog = newNode;
        }
        else
        {
            queue->headDog = queue->lastDog = newNode;
        }
    }
    else
    {
        if(queue->lastCat != NULL)
        {
            queue->lastCat->next = newNode;
            queue->lastCat = newNode;
        }
        else
            queue->lastCat = queue->headCat = newNode;
    }
    
    return 1;
}