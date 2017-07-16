package Chapter10;

/**
 * Created by cmidler on 7/15/17.
 * Find Duplicates: You have an array with all the numbers from 1 to N, where N is at most 32,000. The
 array may have duplicate entries and you do not know what N is. With only 4 kilobytes of memory
 available, how would you print all duplicate elements in the array?
 */
public class Question8 {
    void findDups(int[] a, int n)
    {
        int size = n/8;
        if (n%8!=0)
            size+=1;
        int[] bitSet = new int[size];
        for(int i  =0; i< n; i++)
        {
            int val = a[i];
            int index = val/8;
            int bitPos = val%8;

            if((bitSet[index] & (1<<bitPos)) !=0)
                System.out.println(val);
            bitSet[index] |=(1<<bitPos);
        }

    }
    public static void main(String[] args) {
        Question8 q8 = new Question8();
        int [] a = new int[10];
        a[0]=0;
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        a[4] = 4;
        a[5] = 5;
        a[6] = 6;
        a[7] = 5;
        a[8] = 3;
        a[9] = 0;
        q8.findDups(a, 10);
    }
}
