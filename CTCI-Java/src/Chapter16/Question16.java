package Chapter16;

/**
 * Created by cptmidler on 7/17/17.
 * Sub Sort: Given an array of integers, write a method to find indices m and n such that if you sorted
 elements m through n, the entire array would be sorted. Minimize n - m (that is, find the smallest
 such sequence).
 EXAMPLE
 Input 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
 Output: (3, 9)
 */
public class Question16 {
    int[] subSort(int[] a)
    {
        if (a == null || a.length ==0)
            return null;
        int[] res = new int[2];


        boolean unSorted = false;
        int largePos = 0;
        int largest = a[0];
        int smallest = Integer.MAX_VALUE;

        for(int i  = 0; i< a.length-1; i++)
        {
            if (!unSorted) {
                if (a[i] > a[i + 1]) {
                    unSorted = true;
                    if(a[i+1]<smallest)
                        smallest = a[i+1];
                    largePos = i+1;
                    largest = a[i];
                }
            }
            else
            {
                System.out.println(a[i]);
                if(a[i] <= smallest)
                {
                    smallest = a[i];
                    largePos = i;
                }
                else if(a[i] < largest)
                {
                    largePos = i;
                }
                else if(largest<=a[i])
                {
                    unSorted = false;
                    i--;
                }
            }

        }

        if(largePos == 0)
            return null;

        int i = 0;
        for(; i<a.length-1; i++)
        {
            if(a[i]>smallest){
                break;
            }
        }

        res[0] = i;
        res[1] = largePos;
        return res;
    }

    public static void main(String[] args) {
        Question16 q16 = new Question16();
        int[] a = {1,2,4,7,10,11,7,12,6,7,16,18,19};
        int[] b = q16.subSort(a);
        System.out.println(Integer.toString(b[0]) + ' ' + Integer.toString(b[1]));
    }
}
