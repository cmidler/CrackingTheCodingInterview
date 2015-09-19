//
//  Question4b.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/4/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given a directed graph, design an algorithm to find out whether there is a route
 between two nodes.
 */

#include "Question4b.h"

void clearVisited(graph_4_b* graph)
{
    for(int i = 0; i<graph->numVertices; i++)
        graph->vertices[i]->visited = 0;
}


int findPathDFS4B(graph_4_b* graph, vertex_4_b* v1, vertex_4_b* v2)
{
    
    if(graph == NULL || v1 == NULL || v2 == NULL)
        return 0;
    
    for(int i = 0; i<v1->numEdges; i++)
    {
        int dest = v1->edges[i]->destination;
        vertex_4_b* tmp = NULL;
        for(int j = 0; j<graph->numVertices; j++)
        {
            if(graph->vertices[j]->visited)
                continue;
            if(graph->vertices[j]->number == dest)
            {
                tmp = graph->vertices[j];
                tmp->visited = 1;
                break;
            }
        }
        if(tmp == NULL)
            continue;
        if(tmp == v2)
            return 1;
        if(findPathDFS4B(graph, tmp, v2))
            return 1;
    }
    
    
    return 0;
}


int isRoute(graph_4_b* graph, vertex_4_b* v1, vertex_4_b* v2)
{
    //it says a route from either so checking with either as origin
    clearVisited(graph);
    if (findPathDFS4B(graph, v1, v2)) {
        clearVisited(graph);
        return 1;
    }
    else
    {
        clearVisited(graph);
        int returnVal = findPathDFS4B(graph, v2, v1);
        clearVisited(graph);
        return returnVal;
    }
}