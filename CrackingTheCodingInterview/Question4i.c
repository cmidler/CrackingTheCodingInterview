//
//  Question4i.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/8/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 You are given a binary tree in which each node contains a value. Design an algorithm
 to print all paths which sum to a given value. The path does not need to
 start or end at the root or a leaf.
 */

#include "Question4i.h"


void printPath(node_4_i* root, node_4_i* node, int value, int sum, char* path, int pathLength, int pathMax)
{
    if(node == NULL)
    {
        return;
    }
    
    char tmpPath[32] = "";
    sprintf(tmpPath, "%d", node->value);
    if(pathLength + strlen(tmpPath) >=pathMax-1)
    {
        pathMax*=2;
        path = realloc(path, pathMax*sizeof(char));
        
        for(int i = 0; i<strlen(tmpPath); i++)
            path[pathLength++] = tmpPath[i];
    }
    
    sum+= node->value;
    if(sum == value)
    {
        path[pathLength] = '\0';
        printf("Path to value is %s\n", path);
    }
    
    printPath(root,node->left, value, sum, path, pathLength, pathMax);
    path = realloc(path, (pathLength+1)*sizeof(char));
    printPath(root,node->right, value, sum, path, pathLength, pathMax);
    if(node != root)
    {
        path = realloc(path, sizeof(char)*32);
        pathLength = 0;
        pathMax = 32;
        printPath(root,node->left, value, node->value, path, pathLength, pathMax);
        path = realloc(path, sizeof(char)*32);
        printPath(root,node->right, value, node->value, path, pathLength, pathMax);
    }
    
    
}

void printPaths(node_4_i* node, int value)
{
    char* path = malloc(sizeof(char)*32);
    printPath(node,node, value, 0, path, 0, 32);
    free(path);
}