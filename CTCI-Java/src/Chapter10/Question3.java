package Chapter10;

/**
 * Created by cmidler on 7/14/17.
 * Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown
 number of times, write code to find an element in the array. You may assume that the array was
 originally sorted in increasing order.
 EXAMPLE
 Input:find5in{15, 16, 19, 20, 25, 1, 3,4,5,7, l0, 14}
 Output: 8 (the index of 5 in the array)
 */

//bugs present. Don't want to put time in to fix
public class Question3 {
    int search(int []a, int n){
        return search(a,n,0,a.length-1);
    }
    int search(int[]a, int n, int low, int high)
    {

        if(low>high) return -1;
        int mid = (low+high)/2;
        int val = a[mid];
        //System.out.println(Integer.toString(val) + ' ' + Integer.toString(n));
        if(val == n)
            return mid;
        else if (val < n)
        {
            if(a[low] > n)
                return search(a,n,mid+1,high);
            else
                return search(a,n,low, mid-1);
        }
        else
        {
            if(a[high]<n)
                return search(a, n, mid+1, high);
            else
                return search(a, n, low, mid-1);
        }
    }

    public static void main(String[] args) {
        Question3 q3 = new Question3();
        int[] array = {15, 16, 19, 20, 25, 1, 3,4,5,7, 10, 14};
        System.out.println(q3.search(array, 5));
        System.out.println(q3.search(array, 16));
        //System.out.println(q3.search(array, 15));

    }
}
