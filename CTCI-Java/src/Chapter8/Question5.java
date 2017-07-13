package Chapter8;

/**
 * Created by cptmidler on 7/13/17.
 * Recursive Multiply: Write a recursive function to multiply two positive integers without using the
 * operator. You can use addition, subtraction, and bit shifting, but you should minimize the number
 of those operations.
 */
//I ended up making this work for negative numbers too as practice
public class Question5 {

    int multiply (int x, int y)
    {
        if(x ==0 || y == 0)
            return 0;
        int tmpX = Math.abs(x);
        int tmpY = Math.abs(y);
        int smaller = Math.min(tmpX, tmpY);
        int larger = Math.max(tmpX, tmpY);
        boolean isNegative = false;
        if(x<0 && y >0)
            isNegative = true;
        else if (x>0 && y<0)
            isNegative = true;
        int res = getRes(larger, smaller);
        if (isNegative)
            return (~res)+1;
        return res;
    }

    int getRes(int x, int y)
    {
        if(x == 1)
            return y;
        if(y==1)
            return x;



        if(y%2 == 0) {
            return getRes(x << 1, y >> 1);
        }
        else {
            return getRes((x << 1), y >> 1)+x;
        }

    }

    public static void main(String[] args) {
        Question5 q5 = new Question5();
        System.out.println(q5.multiply(2,7));
        System.out.println(q5.multiply(2,0));
        System.out.println(q5.multiply(-5,7));
        System.out.println(q5.multiply(2,-7));
        System.out.println(q5.multiply(-8,-7));
    }

}
