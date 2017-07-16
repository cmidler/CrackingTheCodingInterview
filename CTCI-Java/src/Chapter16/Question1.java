package Chapter16;

/**
 * Created by cmidler on 7/15/17.
 * Number Swapper: Write a function to swap a number in place (that is, without temporary variables).
 */
public class Question1 {
    void swap(int[] a, int x, int y)
    {
        a[x]^=a[y];
        a[y]^=a[x];
        a[x]^=a[y];
    }

    public static void main(String[] args) {
        int [] a = {5, 10};
        Question1 q1 = new Question1();
        q1.swap(a,0,1);
        System.out.println(a[0]);
        System.out.println(a[1]);
    }
}
