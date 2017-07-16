package Chapter16;

/**
 * Created by cmidler on 7/15/17.
 * Factorial Zeros: Write an algorithm which computes the number of trailing zeros in n factorial.
 */
public class Question5 {
    long factorial(int n)
    {
        long f = n;
        n--;
        while(n>1)
        {
            f*=(n--);
        }

        return f;
    }
    int countTrailingZeros(int n)
    {
        long f = factorial(n);

        int zeroes = 0;
        while(f%10 ==0)
        {
            zeroes+=1;
            f/=10;
        }
        return zeroes;
    }

    public static void main(String[] args) {
        Question5 q5 = new Question5();
        int n = 10;
        System.out.println(q5.factorial(n));
        System.out.println(q5.countTrailingZeros(n));
    }
}
