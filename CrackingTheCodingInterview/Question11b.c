//
//  Question11b.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write a method to sort an array of strings so that all the anagrams are next to
 each other
 */

#include "Question11b.h"


int isAnagram(char* string)
{
    int len = (int)strlen(string);
    for(int i=0; i<len/2; i++)
        if(string[i] != string[len-i-1])
            return 0;
    
    return 1;
}

char** sortAnagrams(char** strings, int n)
{
    char** anagrams = malloc(sizeof(char*)*n);
    if(anagrams == NULL)
        return NULL;
    char** notAnagrams = malloc(sizeof(char*)*n);
    if(notAnagrams == NULL)
    {
        free(anagrams);
        return NULL;
    }
    
    int x = 0;
    int y = 0;
    for(int i = 0; i<n; i++)
    {
        if(isAnagram(strings[i]))
            anagrams[x++] = strings[i];
        else
            notAnagrams[y++] = strings[i];
    }
    
    for(int i = 0; i<y; i++)
        anagrams[x++] = notAnagrams[i];
    
    free(notAnagrams);
    return anagrams;
}