package Chapter16;

/**
 * Created by cmidler on 7/15/17.
 * Operations: Write methods to implement the multiply, subtract, and divide operations for integers.
 The results of all of these are integers. Use only the add operator.
 12*5 = 60
 12-5 = 7
 12/5 = 2
 */
public class Question9 {
    int multiply(int a, int b)
    {
        if(a == 0 || b == 0)
            return 0;

        int res = 0;
        boolean isNegative = false;
        if((a<0 && b>0) || (a>0 && b<0))
            isNegative = true;

        if(a<0)
            a = negate(a);
        if(b<0)
            b = negate(b);

        for(int i = 0; i< b; i++)
            res+=a;
        if(isNegative)
            res = negate(res);
        return res;
    }

    int subtract(int a, int b)
    {

        return a + negate(b);
    }

    int divide(int a, int b)
    {
        if(b==0) throw new IllegalArgumentException("Divide by zero");
        if(a == 0) return 0;

        int res = 0;
        boolean isNegative = false;
        if((a<0 && b>0) || (a>0 && b<0))
            isNegative = true;

        if(a<0)
            a = negate(a);
        if(b<0)
            b = negate(b);

        while(a>b)
        {
            res++;
            a=subtract(a,b);
        }

        if(isNegative)
            negate(res);
        return res;
    }



    int negate(int n)
    {
        int add = 1;
        if(n>0)
            add = -1;
        int additional = 0;
        while(n!=0)
        {
            n+=add;
            additional+=add;
        }
        return additional;
    }

    public static void main(String[] args) {
        Question9 q9 = new Question9();
        int a = 12;
        int b = 5;
        System.out.println(q9.multiply(a,b));
    }
}
