package Chapter1;

/**
 * Created by cmidler on 7/7/17.
 * One Away: There are three types of edits that can be performed on strings: insert a character,
 remove a character, or replace a character. Given two strings, write a function to check if they are
 one edit (or zero edits) away.
 EXAMPLE
 pale, ple -> true
 pales. pale -> true
 pale. bale -> true
 pale. bake -> false
 */
public class Question5 {

    public boolean oneAway(String s1, String s2)
    {
        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();
        String first = s1;
        String second = s2;
        if(s1.equals(s2))
            return true;

        boolean sameLength = true;
        int s1L = s1.length();
        int s2L = s2.length();

        if(s1L!=s2L){
            sameLength = false;
            if(s1L<s2L){
                if((s2L-s1L)!=1)
                    return false;
                first = s2;
                second = s1;
                int tmp = s1L;
                s1L = s2L;
                s2L = tmp;
            }
            else {
                if ((s1L - s2L) != 1)
                    return false;
            }
        }

        boolean foundDiff = false;
        for(int i = 0; i<first.length(); i++)
        {
            if(foundDiff){
                if(sameLength)
                {
                    if(first.charAt(i)!= second.charAt(i))
                        return false;
                }
                else if (first.charAt(i)!=second.charAt(i-1))
                    return false;
            }
            else if(i == s1L-1)
                return true;
            else if(first.charAt(i)!=second.charAt(i))
                foundDiff = true;
        }

        return true;
    }

    public static void main(String[] args) {
        Question5 q5 = new Question5();
        System.out.println(q5.oneAway("pale","ple"));
        System.out.println(q5.oneAway("pales","pale"));
        System.out.println(q5.oneAway("pale","bale"));
        System.out.println(q5.oneAway("pale","bake"));

    }
}
