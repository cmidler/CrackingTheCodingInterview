package Chapter10;

/**
 * Created by cmidler on 7/14/17.
 * Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
 method. It does, however, have an elementAt (i) method that returns the element at index i in
 0(1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data
 structure only supports positive integers.) Given a Listy which contains sorted, positive integers,
 find the index at which an element x occurs. If x occurs multiple times, you may return any index.
 */
//just whiteboarded this one since Listy doesn't exist
import java.util.Arrays;
public class Question4 {
    public static void main(String[] args) {
        int [] a = new int[7];
        a[0]=0;
        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
        a[4] = 4;
        a[5] = 5;
        a[6] = 6;

        System.out.println(Arrays.binarySearch(a,5));
    }
}
