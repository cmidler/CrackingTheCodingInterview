//
//  Question11h.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Imagine you are reading in a stream of integers. Periodically, you wish to be able
 to look up the rank of a number x (the number of values less than or equal to x).
 Implement the data structures and algorithms to support these operations.That
 is, implement the method track(int x), which is called when each number
 is generated, and the method getRankOfNumber(int x), which returns the
 number of values less than or equal to x (not including x itself).
 EXAMPLE
 Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3
 getRankOfNumber(1) = 0
 getRankOfNumber(3) = 1
 getRankOfNumber(4) = 3
 */

#include "Question11h.h"


void freeStream11H(stream_11_h* stream)
{
    free(stream->numbers);
    free(stream);
    
}

stream_11_h* createStream(int size)
{
    stream_11_h* stream = malloc(sizeof(stream_11_h));
    if(stream == NULL)
        return NULL;
    
    int* array = malloc(sizeof(int)*size);
    if(array == NULL)
    {
        free(stream);
        return NULL;
    }
    
    
    stream->numbers = array;
    stream->max = size;
    stream->total = 0;
    
    return stream;
}

int insert(stream_11_h* stream, int x)
{
    int i = 0;
    for(; i<stream->total; i++)
    {
        if(stream->numbers[i]>x)
            break;
    }
    
    for(int j = stream->total; j>i; j--)
        stream->numbers[j] = stream->numbers[j-1];
    
    stream->numbers[i] = x;
    stream->total++;
    return i;
}



int track(stream_11_h* stream, int x)
{
    //see if we need more space
    if(stream->max == stream->total)
    {
        stream->max*=2;
        stream = realloc(stream,stream->max);
        if(stream == NULL)
            return -1;
    }
    
    return insert(stream,x);
    
}

int binSearch(stream_11_h* stream, int x, int low, int high)
{
    
    int mid = (high+low)/2;
    
    if(stream->numbers[mid] == x)
    {
        int i = mid;
        for(; i<= high; i++)
        {
            if(stream->numbers[i]>x)
                break;
        }
        i--;
        
        return i;
        
    }
    
    if(high<low)
        return -1;
    
    if(stream->numbers[mid]> x)
        return binSearch(stream, x, low, mid-1);
    else
        return binSearch(stream, x, mid+1, high);
    
}

int getRankOfNumber(stream_11_h* stream, int x)
{
    return binSearch(stream, x, 0, stream->total-1);
}


