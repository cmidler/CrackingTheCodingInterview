//
//  MergeSort.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/3/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/* My implementation of merge sort */

#include "MergeSort.h"

void merge(int *array , int *left ,int *right, int leftCount,int rightCount) {
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while(1)
    {
        if(i >= leftCount || j >= rightCount)
            break;
        
        if(left[i]  < right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }
    while(i < leftCount)
        array[k++] = left[i++];
    while(j < rightCount)
        array[k++] = right[j++];
}


void mergeSort(int *array, int n) {
    int k = 0;
    if(n < 2)
        return;
    
    int mid = n/2;
    
    int* left = (int*)malloc(sizeof(int)*mid);
    int* right = (int*)malloc(sizeof(int)*(n-mid));
    
    for(int i = 0;i<mid;i++)
        left[i] = array[i];
    for(int j = mid;j<n;j++)
        right[k++] = array[j];
    
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(array,left, right, mid,n-mid); 
    free(left);
    free(right);
}

