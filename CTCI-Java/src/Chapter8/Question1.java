package Chapter8;

import java.util.HashMap;

/**
 * Created by cptmidler on 7/12/17.
 * Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
 steps at a time. Implement a method to count how many possible ways the child can run up the
 stairs.
 */
public class Question1 {
    public int steps(int n,  HashMap<Integer, Integer> memo)
    {
        if (n <0) return 0;
        if(n==0) return 1;

        if(!memo.containsKey(n))
            memo.put(n, steps(n-1,memo) + steps(n-2,memo) + steps(n-3,memo));

        return memo.get(n);
    }

    public static void main(String[] args) {
        Question1 q1 = new Question1();
        HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();
        System.out.println(q1.steps(1,memo));
        System.out.println(q1.steps(2,memo));
        System.out.println(q1.steps(3,memo));
        System.out.println(q1.steps(4,memo));
        System.out.println(q1.steps(5,memo));
        System.out.println(q1.steps(6,memo));
        System.out.println(q1.steps(7,memo));
    }
}
