package Chapter17;

import java.util.HashSet;
import java.util.Random;

/**
 * Created by cmidler on 7/17/17.
 * Random Set: Write a method to randomly generate a set of m integers from an array of size n. Each
 element must have equal probability of being chosen.
 */
public class Question3 {

    HashSet<Integer> getSet(int m, int[]n)
    {
        if(n ==null || n.length < m || m<=0)
            return null;
        HashSet<Integer> set = new HashSet<Integer>();
        int size = n.length;
        int i = 0;
        Random r = new Random();
        while(i<m)
        {
            int j = r.nextInt(size);
            if(!set.contains(n[j]))
            {
                i++;
                set.add(n[j]);
            }
        }
        return set;
    }
}
