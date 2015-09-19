//
//  Question11c.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/2/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Given a sorted array of n integers that has been rotated an unknown number of
 times, write code to find an element in the array. You may assume that the array
 was originally sorted in increasing order.
 EXAMPLE
 Input: find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
 Output: 8 (the index of 5 in the array)
 */

#include "Question11c.h"

int search(int* input, int left, int right, int find)
{
    int mid = (right+left)/2;
    if(find == input[mid])
        return mid;
    
    if(right<left)
        return -1;
    
    
    
    if (input[left] < input[mid]) { // Left is normally ordered.
        if (find >= input[left] && find < input[mid]) {
            return search(input, left, mid - 1, find); // Search left
        } else {
            return search(input, mid + 1, right, find); // Search right
        }
    } else if (input[mid] < input[left]) { // Right is normally ordered.
        if (find > input[mid] && find <= input[right]) {
            return search(input, mid + 1, right, find); // Search right
        } else {
            return search(input, left, mid - 1, find); // Search left
        }
    } else if (input[left] == input[mid])
    { // Left half is all repeats
        if (input[mid] != input[right]) { // If right is diff., search it
            return search(input, mid + 1, right, find); // search right
        } else
        { // Else, we-have to search both halves
            int result = search(input, left, mid - 1, find); // Search left
            if (result == -1) {
                return search(input, mid + 1, right, find); // Search right
            } else {
                return result;
            }
        }
    }
    return -1;
}

int findElementInRotatedArray(int n, int* input, int find)
{
    if(n == 0 || input == NULL)
        return -1;
    
    return search(input, 0, n-1,find);
}

