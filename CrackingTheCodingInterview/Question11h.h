//
//  Question11h.h
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#ifndef __CrackingTheCodingInterview__Question11h__
#define __CrackingTheCodingInterview__Question11h__

#include <stdio.h>
#include <stdlib.h>

typedef struct stream11H{
    int* numbers;
    int total;
    int max;
}stream_11_h;


int track(stream_11_h* stream, int x);
int getRankOfNumber(stream_11_h* stream, int x);
stream_11_h* createStream(int size);
void freeStream11H(stream_11_h* stream);


#endif /* defined(__CrackingTheCodingInterview__Question11h__) */
