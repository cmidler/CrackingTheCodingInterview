package Chapter16;

import java.util.Arrays;
import java.util.HashSet;

/**
 * Created by cmidler on 7/17/17.
 * Sum Swap: Given two arrays of integers, find a pair of values (one value from each array) that you
 can swap to give the two arrays the same sum.
 EXAMPLE
 Input: (4, 1,2, 1, 1, 2) and (3, 6, 3, 3)
            11  15
 sumA-a+b = sumB-b+a
 a-b = (sumA-sumB)/2
 Output: (1, 3)
 */
public class Question21 {
    int []sumSwap(int[]a, int[]b)
    {
        int sumA = 0;
        int sumB = 0;

        HashSet<Integer> aSet = new HashSet<Integer>();
        HashSet<Integer> bSet = new HashSet<Integer>();

        for(int i = 0; i< a.length; i++) {
            sumA += a[i];
            aSet.add(a[i]);
        }

        for(int i = 0; i<b.length; i++) {
            sumB += b[i];
            bSet.add(b[i]);
        }



        if((sumA-sumB)%2 ==1)
            return null;

        for(int i =0; i<a.length; i++)
        {
            int target = getTarget(a[i], sumA, sumB);
            if(bSet.contains(target))
            {
                return new int[]{a[i],target};
            }
        }

        return null;

    }

    int getTarget(int a, int sumA, int sumB)
    {
        return a - ((sumA-sumB)/2);
    }

    public static void main(String[] args) {
        Question21 q21 = new Question21();
        int[] a = {4,1,2,1,1,2};
        int[] b = {3,6,3,3};

        int[] c = q21.sumSwap(a,b);
        System.out.println(c[0]);
        System.out.println(c[1]);
    }

}
