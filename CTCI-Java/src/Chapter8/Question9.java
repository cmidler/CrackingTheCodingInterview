package Chapter8;

/**
 * Created by cptmidler on 7/13/17.\
 * Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
 of n pairs of parentheses.
 EXAMPLE
 Input: 3
 Output: « () ) ) J «) (», «» () J () ( (», () () ()
 */
public class Question9 {
    int i = 0;
    void printParens(int n)
    {
        recurseParens(n,n, "");
    }

    void recurseParens(int left, int right, String paren)
    {
       if (left == 0)
        {
            StringBuilder p = new StringBuilder(paren);
            for(int i = right; i>0; i--)
                p.append(')');
            i++;
            System.out.println(p.toString()+ " " + Integer.toString(i));
        }
        else
        {
            if(left< right)
                recurseParens(left, right-1, paren+')');
            recurseParens(left-1, right, paren+'(');
        }
    }


    public static void main(String[] args) {
        Question9 q9 = new Question9();
        q9.printParens(3);
        System.out.println("\n\n");
        q9.printParens(5);
    }
}
