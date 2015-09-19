//
//  Question4b.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/4/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question4b__
#define __CrackingTheCodingInterview__Question4b__

#include <stdio.h>
#include <stdlib.h>





typedef struct edge4B{
    int origin;
    int destination;
}edge_4_b;

typedef struct vertex4B{
    int number;
    int value;
    int visited;
    int numEdges;
    int maxEdges;
    edge_4_b** edges;
    
}vertex_4_b;

typedef struct graph4B{
    vertex_4_b** vertices;
    int numVertices;
}graph_4_b;


#endif /* defined(__CrackingTheCodingInterview__Question4b__) */
