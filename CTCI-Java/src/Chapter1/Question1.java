package Chapter1;

/**
 * Created by cptmidler on 7/6/17.
 * Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
 cannot use additional data structures?
 */
import java.util.HashMap;
import java.util.Arrays;
public class Question1 {
    //O(n) space and time
    boolean hasUCharacters(String s) {
        HashMap h = new HashMap();
        for(int i = 0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(h.containsKey(c))
                return false;
            h.put(c,1);
        }
        return true;
    }

    //assuming lowercase english letters only (26 values in 8 byte int)
    boolean betterHasUCharacters(String s){
        int check = 0;
        for(int i =0; i<s.length(); i++)
        {
            int val = s.charAt(i) - 'a';
            if((check & (1 <<val)) >0)
                return false;
            check |=(1<<val);
        }

        return true;
    }

    public static void main(String[] args) {
        System.out.println(new Question1().hasUCharacters("test"));
        System.out.println(new Question1().hasUCharacters("true"));
        System.out.println(new Question1().betterHasUCharacters("test"));
        System.out.println(new Question1().betterHasUCharacters("true"));
    }
}
