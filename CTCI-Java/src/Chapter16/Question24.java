package Chapter16;

import java.util.HashSet;
import java.util.Arrays;
/**
 * Created by cmidler on 7/17/17.
 * Pairs with Sum: Design an algorithm to find all pairs of integers within an array which sum to a
 specified value.
 */
public class Question24 {
    class Pair{
        int low;
        int high;

        public Pair(int low, int high)
        {
            this.low = low;
            this.high = high;
        }
    }
    HashSet<Pair> pairsWithSum(int[] a, int sum)
    {
        if(a==null || a.length <= 1)
            return null;
        HashSet<Pair> pairs = new HashSet<Pair>();
        Arrays.sort(a);

        int j = a.length-1;
        for(int i = 0; i<a.length-1 && i<j;)
        {
            int val = a[i] + a[j];
            if(val > sum)
            {
                j--;
            }
            else if(val<sum)
            {
                i++;
            }
            else
            {
                pairs.add(new Pair(a[i], a[j]));
                i++;
                j--;
            }
        }

        if(pairs.isEmpty())
            return null;
        return pairs;
    }
}
