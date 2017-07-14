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
        return numWays(n, denoms, 0, new HashMap<String, Integer>());
    }

    int numWays(int amount, int[] denoms, int index, HashMap<String, Integer> map)
    {

        if(index >= (denoms.length-1))
            return 1;

        String key = Integer.toString(amount) + " "+Integer.toString(index);

        if (map.containsKey(key)) {
            return map.get(key);
        }

        int denomAmount = denoms[index];
        int ways = 0;
        for(int i = 0; i*denomAmount <=amount ; i++)
        {
            int amountRemaining = amount - i*denomAmount;
            ways += numWays(amountRemaining, denoms, index+1, map);
        }

        key = Integer.toString(amount) + " "+Integer.toString(index);
        map.put(key, ways);
        return ways;

    }

    public static void main(String[] args) {
        Question11 q11 = new Question11();
        System.out.println(q11.makeCents(35));
    }
}
