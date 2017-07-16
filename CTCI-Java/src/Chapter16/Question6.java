package Chapter16;


import java.util.Arrays;

/**
 * Created by cmidler on 7/15/17.
 * Smallest Difference: Given two arrays of integers, compute the pair of values (one value in each
 array) with the smallest (non-negative) difference. Return the difference.
 EXAMPLE
 Input{1,3,15,11,2} {23, 127, 235,19, 8}
 Output 3. That is, the pair (11, 8).
 */
public class Question6 {
    int smallestDifference(int [] a, int [] b)
    {
        if(a == null || b == null || a.length == 0 || b.length == 0)
            return -1;

        Arrays.sort(a);
        Arrays.sort(b);
        int size = Math.max(a.length,b.length);
        int aIndex = 0;
        int bIndex = 0;

        int smallestDifference = Integer.MAX_VALUE;
        int aPair = 0;
        int bPair = 0;
        while(aIndex<a.length && bIndex<b.length)
        {
            int aVal = a[aIndex];
            int bVal = b[bIndex];
            int difference = Math.abs(aVal - bVal);
            if(difference < smallestDifference)
            {
                smallestDifference = difference;
                aPair = aVal;
                bPair = bVal;
            }

            if(aVal < bVal)
                aIndex++;
            else if(bVal < aVal)
                bIndex++;
            else
            {
                smallestDifference = 0;

                break;
            }
        }


        return smallestDifference;
    }

    public static void main(String[] args) {
        Question6 q6 = new Question6();
        int[] a = {1,3,15,11,2};
        int[] b = {23, 127, 235,19, 8, 5, 29};
        System.out.println(q6.smallestDifference(a,b));

    }
}
