package Chapter8;

/**
 * Created by cptmidler on 7/13/17.
 * Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and
 pennies (1 cent), write code to calculate the number of ways of representing n cents.
 */
import java.util.HashMap;
public class Question11 {

    int makeCents(int n)
    {
        if (n<0)
            return 0;
        int[] denoms = {25,10,5,1};
        return numWays(n, denoms, 0, new HashMap<Integer, Integer>());
    }

    int numWays(int n, int[] denoms, int index, HashMap<Integer, Integer> map)
    {
        if (map.containsKey(n))
            return map.get(n);

        if(index >= denoms.length)
            return 1;

        int amount = denoms[index];
        int ways = 0;
        for(int i = 0; i*amount <=n; i++)
        {
            int amountRemaining = amount - i*amount;
            ways+=numWays(amountRemaining,denoms, index+1, map);

        }

        map.put(n, ways);

        return map.get(n);


    }

    public static void main(String[] args) {
        Question11 q11 = new Question11();
        System.out.println(q11.makeCents(43));
    }
}
