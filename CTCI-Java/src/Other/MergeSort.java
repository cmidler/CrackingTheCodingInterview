package Other;

import java.util.Random;

/**
 * Created by cptmidler on 7/18/17.
 */
public class MergeSort {

    public void sort(int[] a)
    {
        mergeSort(a, 0, a.length-1);
    }

    private void mergeSort(int[]a, int low, int high)
    {
        if(low>=high)
            return;

        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }

    private void merge(int[]a, int low, int mid, int high)
    {
        int[]b = new int[a.length];
        for(int i = low; i<=high; i++)
            b[i] = a[i];

        int left = low;
        int right = mid+1;
        int current = low;

        while(left<=mid && right<=high)
        {
            if(b[left] < b[right])
            {
                a[current] = b[left];
                left++;
            }
            else
            {
                a[current] = b[right];
                right++;
            }
            current++;
        }

        int remaining = mid-left;
        for(int i = 0; i<= remaining; i++)
            a[current+i] = b[left+i];


    }

    public static void main(String[] args) {
        MergeSort m = new MergeSort();
        Random r = new Random();
        int[] a = new int[20];
        for(int i = 0; i<20; i++) {
            a[i] = r.nextInt(50);
            System.out.println(a[i]);
        }

        System.out.println("\n\n");
        m.sort(a);
        for(int i = 0; i<20; i++)
            System.out.println(a[i]);

    }
}
