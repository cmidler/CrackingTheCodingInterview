//
//  Question3g.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/4/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question3g__
#define __CrackingTheCodingInterview__Question3g__

#include <stdio.h>
#include <stdlib.h>


typedef struct node3G
{
    int isDog;
    int order;
    struct node3G* next;
}node_3_g;

typedef struct queue3G
{
    int total;
    node_3_g* headDog;
    node_3_g* headCat;
    node_3_g* lastDog;
    node_3_g* lastCat;
}queue_3_g;

node_3_g* dequeueDog(queue_3_g* queue);
node_3_g* dequeueCat(queue_3_g* queue);
node_3_g* dequeueAny(queue_3_g* queue);
int enqueue(queue_3_g* queue, int isDog);

#endif /* defined(__CrackingTheCodingInterview__Question3g__) */
