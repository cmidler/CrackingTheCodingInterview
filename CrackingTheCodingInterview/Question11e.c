//
//  Question11e.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given a sorted array of strings which is interspersed with empty strings, write a
 method to find the location of a given string.
 EXAMPLE
 Input: find "ball" in {"at", "", "", "", "ball", "", "", "car",
                        "", "", "dad", "", ""}
 Output: 4
 */

#include "Question11e.h"


int binarySearch(char** strings, int low, int high, char* search)
{
    int mid = (low+high)/2;
    
    
    
    char* newStr = strings[mid];
    int len = (int)strlen(newStr);
    if(!len)
    {
        while(1)
        {
            
            int midLow = mid-1;
            int midHigh = mid+1;
            if(midLow<low && midHigh>high)
                return -1;
            else if(strlen(strings[midLow]))
            {
                mid = midLow;
                break;
            }
            else if(strlen(strings[midHigh]))
            {
                mid = midHigh;
                break;
            }
            
            midLow--;
            midHigh++;
        }
        
    }
    if(!strcmp(strings[mid], search))
        return mid;
    
    if(high<low)
        return -1;
    
    if(strcmp(strings[mid], search)>0)
        return binarySearch(strings, low, mid-1, search);
    else
        return binarySearch(strings, mid+1, high, search);
    
}


int indexOfString(char** strings, int n, char* search)
{
    if(strings == NULL || n == 0 || search == NULL || !strlen(search))
        return -1;
    
    return binarySearch(strings, 0, n-1, search);
}