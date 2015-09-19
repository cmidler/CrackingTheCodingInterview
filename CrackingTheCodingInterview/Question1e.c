//
//  Question1e.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Implement a method to perform basic string compression using the counts
 of repeated characters. For example, the string aabcccccaaa would become
 a2blc5a3. If the "compressed" string would not become smaller than the original
 string, your method should return the original string.
 */

#include "Question1e.h"

//assuming only letters.  Numbers would break this
char* compressedString(char* str)
{
    
    
    int len = (int) strlen(str);
    
    if(len<=1) return str;
    
    char* compressedStr = malloc(sizeof(char)*len+1);
    
    if(!compressedStr) return str;
    
    char tmp = str[0];
    int count = 1;
    int numInCompressed = 0;
    char countStr[10];
    
    for(int i = 1; i < len; i++)
    {
        char c = str[i];
        if(c == tmp)
            count++;
        else
        {
            snprintf(countStr,10,"%d",count);
            compressedStr[numInCompressed++] = tmp;
            if(numInCompressed == len)
            {
                free(compressedStr);
                return str;
            }
            for(int j = 0; ; j++)
            {
                if(numInCompressed == len)
                {
                    free(compressedStr);
                    return str;
                }
                if(countStr[j] == '\0')
                    break;
                else
                    compressedStr[numInCompressed++] = countStr[j];
            }
            count = 1;
            tmp = c;
        }
    }
    
    
    snprintf(countStr,10,"%d",count);
    compressedStr[numInCompressed++] = tmp;
    if(numInCompressed == len)
    {
        free(compressedStr);
        return str;
    }
    for(int j = 0; ; j++)
    {
        if(numInCompressed > len)
        {
            free(compressedStr);
            return str;
        }
        if(countStr[j] == '\0')
            break;
        else
            compressedStr[numInCompressed++] = countStr[j];
    }

    compressedStr[numInCompressed] = '\0';
    return compressedStr;
    
}