package Chapter17;

/**
 * Created by cmidler on 7/17/17.
 * Add Without Plus: Write a function that adds two numbers. You should not use + or any arithmetic
 operators.
 */
public class Question1 {

    int add(int x, int y)
    {
        boolean carry = false;
        int res = 0;



        for(int i = 0; i<32; i++)
        {
            int a = (x & (1<<i))>>i;
            int b = (y & (1<<i))>>i;

            int c = a&b;
            if(c ==1)
            {
                if(carry)
                {
                    res |= (1<<i);
                }
                carry = true;
            }
            else
            {
                c = a|b;
                if(c == 1) {
                    if (!carry) {
                        res |= (1<<i);
                        carry = false;
                    }
                    else
                        carry = true;
                }
                else
                {
                    if(carry)
                        res |=(1<<i);
                    carry = false;
                }

            }

        }

        return res;
    }

    public static void main(String[] args) {
        Question1 q1 = new Question1();
        System.out.println(q1.add(2,5));

    }
}
