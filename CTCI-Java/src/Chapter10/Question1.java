package Chapter10;

/**
 * Created by cmidler on 7/14/17.
 * Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the
 end to hold B. Write a method to merge B into A in sorted order.
 */
public class Question1 {
    void mergeArrays(int[]a, int[]b, int lastA, int lastB)
    {
        int endOfA = a.length-1;
        int indexA = lastA-1;
        int indexB = lastB-1;

        while(indexB>=0)
        {
            if (indexA >=0 && a[indexA] > b[indexB]) {
                a[endOfA--] = a[indexA--];
            }
            else
            {
                a[endOfA--] = a[indexA--];
            }
        }
    }

}
