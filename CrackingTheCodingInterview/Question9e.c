//
//  Question9e.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/1/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Write a method to compute all permutations of a string.
 */

#include "Question9e.h"

void swap(char* x, char* y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

int compare(const void* x, const void* y)
{
    return *((char*)x)-*((char*)y);
}


//decided to write a harder method for getting unique combinations of permutations
void sortedUniqueCombinations(char* arr, int curr, int size)
{
    if(curr == size-1)
    {
        for(int a=0; a<size; a++)
            printf("%c", arr[a]);
        printf("\n");
    }
    
    else
    {
        for(int i=curr; i<size; i++)
        {
            if(curr!=i && arr[curr] == arr[i])
                continue;
            //swap
            swap(&(arr[curr]), &(arr[i]));
            //perm
            sortedUniqueCombinations(arr, curr+1, size);
            //swap back
            swap(&(arr[curr]), &(arr[i]));
        }
    }

}

void uniqueCombinations(char* arr)
{
    qsort(arr, (int)strlen(arr), sizeof(arr[0]), compare);
    sortedUniqueCombinations(arr, 0, (int)strlen(arr));
}

/* arr is the string, curr is the current index to start permutation from and size is sizeof the arr */
void permutation(char * arr, int curr, int size)
{
    if(curr == size-1)
    {
        for(int a=0; a<size; a++)
            printf("%c", arr[a]);
        printf("\n");
    }
    
    
    else
    {
        for(int i=curr; i<size; i++)
        {
            //swap
            swap(&(arr[curr]), &(arr[i]));
            //perm
            permutation(arr, curr+1, size);
            //swap back
            swap(&(arr[curr]), &(arr[i]));
           
        }
    }
}
