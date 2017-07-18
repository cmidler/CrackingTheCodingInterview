package Chapter17;

import java.util.Random;

/**
 * Created by cmidler on 7/17/17.
 * Missing Number: An array A contains all the integers from 0 to n, except for one number which
 is missing. In this problem, we cannot access an entire integer in A with a single operation. The
 elements of A are represented in binary, and the only operation we can use to access them is "fetch
 the jth bit of A[i]," which takes constant time. Write code to find the missing integer. Can you do it
 in O(n) time?
 */

//bleh, read the question wrong and thought I had a sorted array. Stupid.
public class Question4 {
    int findMissing(int[] a, int n)
    {
        if(a == null || a.length<=0 || n<=0)
            return -1;
        for(int i = 0; i<n; i++)
        {
            byte b = getJthBit(a[i], 0);
            int isOne =  b&1;
            if(isEven(i) && isOne ==1)
                return i-1;
        }
        return -1;
    }

    boolean isEven(int i)
    {
        if(i%2 == 0)
            return true;
        return false;
    }


    byte getJthBit(int val, int j)
    {
        return 1;
    }
}
