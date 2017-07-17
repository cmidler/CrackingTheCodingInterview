package Chapter16;

import java.util.ArrayList;

/**
 * Created by cptmidler on 7/17/17.
 * Contiguous Sequence: You are given an array of integers (both positive and negative). Find the
 contiguous sequence with the largest sum. Return the sum.
 EXAMPLE
 Input 2, -8, 3, -2, 4, -10
 Output S (Le., {3, -2, 4})
 */
public class Question17 {

    int[] contiguousSequence(int [] a)
    {
        if (a==null || a.length == 0)
            return null;
        int largest = getLargest(a);

        if (largest<=0) {
            return new int[]{largest};
        }

        int maxSum = 0;
        int sum = 0;
        int lowIndex = 0;
        int highIndex = 0;

        int curLow = 0;

        for(int i = 0; i< a.length; i++)
        {
            if(sum == 0)
            {
                curLow = i;
            }

            sum+=a[i];
            if(sum>maxSum)
            {
                maxSum = sum;
                lowIndex = curLow;
                highIndex = i;
            }
            else if(sum<0)
            {
                sum = 0;
            }
        }

        int [] res = new int[highIndex-lowIndex+1];
        for(int i = lowIndex; i<=highIndex; i++)
        {
            res[i-lowIndex] = a[i];
        }
        return res;
    }

    int getLargest(int []a)
    {
        int largest = a[0];
        for(int i =1; i<a.length; i++)
            largest = Math.max(a[i], largest);
        return largest;
    }

    public static void main(String[] args) {
        Question17 q17 = new Question17();

        int a[] = {2,3,-8,-1,2,4,-2,3};
        int b[] = q17.contiguousSequence(a);

        for(int i = 0; i<b.length; i++)
            System.out.println(b[i]);
    }
}
