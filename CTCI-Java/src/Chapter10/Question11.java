package Chapter10;

/**
 * Created by cmidler on 7/15/17.
 * Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to
 the adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers.
 For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array
 of integers, sort the array into an alternating sequence of peaks and valleys.
 EXAMPLE
 Input: {5, 3, 1,2, 3}
 Output: {5, 1,3,2, 3}
 */
import java.util.Arrays;
import java.util.Random;

public class Question11 {
    void peaksAndValleys(int [] a)
    {
        Arrays.sort(a);
        for(int i = 0; i<a.length-1; i+=2)
        {
            int tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }

    public static void main(String[] args) {
        Question11 q11 = new Question11();
        int [] a = new int [10];
        int [] b = new int[11];
        Random r = new Random();
        for(int i = 0; i<10; i++)
        {
            a[i] = r.nextInt(100);
            b[i] = r.nextInt(100);
        }
        b[10] = r.nextInt(100);

        q11.peaksAndValleys(a);
        q11.peaksAndValleys(b);
        for(int i = 0; i<10; i++)
            System.out.print(Integer.toString(a[i]) + ", ");
        System.out.println();
        for(int i = 0; i<11; i++)
            System.out.print(Integer.toString(b[i]) + ", ");
        System.out.println();

    }
}
