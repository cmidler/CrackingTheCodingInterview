//
//  QuickSort.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/3/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#include "QuickSort.h"


void quickSwap(int* array, int left, int right)
{
    int tmp = array[left];
    array[left] = array[right];
    array[right] = tmp;
}


int partition(int* array, int left, int right)
{
    int mid = (left+right)/2;
    int pivot = array[mid];
    
    while(left< right)
    {
        while(array[left]<pivot)
        {
            if(left> right)
                break;
            left++;
        }
        
        while(array[right]>pivot)
        {
            if(right<left)
                break;
            right--;
        }
        
        if(left<right)
        {
            quickSwap(array, left, right);
            left++;
            right--;
        }
    }
    
    return left;
}


void quickSort(int* array, int left, int right)
{
    if(array == NULL || left < 0 || right < 0)
        return;
    
    int tmp = partition(array, left, right);
    if(left<tmp-1)
        quickSort(array, left, tmp-1);
    if(tmp<right)
        quickSort(array, tmp, right);
    
}

