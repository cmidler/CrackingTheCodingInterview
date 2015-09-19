//
//  Recursion1.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 9/9/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

/*
 Problem : Write the reverse() function recursively. This function takes a string and the length of the string as arguments and returns the same string with its characters in the reverse order.
 */

#include "Recursion1.h"

void recursiveReverse1(char* string, int n)
{
    int len = (int)strlen(string);
    if(n == 0 || n < len/2)
        return;
    
    char tmp = string[n-1];
    string[n-1] = string[len-n];
    string[len-n] = tmp;
    recursiveReverse1(string, n-1);
}

int count_spaces(char *s)
{
    if(s == NULL || s[0] == '\0')
        return 0;
    else
        return isspace(s[0]) + count_spaces(s+1);
}


/*Problem : A palindrome is a sequence of characters or numbers that looks the same forwards and backwards. For example, "Madam, I'm Adam" is a palindrome because it is spelled the same reading it from front to back as from back to front. The number 12321 is a numerical palindrome. Write a function that takes a string and its length as arguments and recursively determines whether the string is a palindrome: int ispalindrome(char *s, int len);
*/

int ispalindrome2(char*s, int len)
{
    int length = (int)strlen(s);
    
    if(len <length/2)
        return 1;
    
    if(s[length-len] != s[len-1])
        return 0;
    
    return ispalindrome2(s, len-1);
}


/*Problem : Write a recursive function void replace(char *s, char from, char to); that changes all occurrences of from in s to to. For example, if s were "steve", and from == 'e' and to == 'a', s would become "stava"*/

void replaceRec3(char* s, char from, char to)
{
    if(s[0] == '\0')
        return;
    
    if(s[0] == from)
        s[0] = to;
    
    replaceRec3(s+1, from, to);
}


/*
 Problem : You have an array of ints sorted in ascending order. Write a function that recursively does a ternary search (splits the data into three sets instead of two) on the array.
 */




