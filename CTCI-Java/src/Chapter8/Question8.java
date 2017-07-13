package Chapter8;

/**
 * Created by cptmidler on 7/13/17.
 * Permutations with Dups: Write a method to compute all permutations of a string whose characters
 are not necessarily unique. The list of permutations should not have duplicates.
 */
import java.util.HashSet;
public class Question8 {
    void getPermutations(String characters)
    {

        printPermutations(characters, "", new HashSet<String>());
    }

    void printPermutations(String characters, String prefix, HashSet<String> set)
    {
        if(characters.length() == 0 && !set.contains(prefix)) {
            set.add(prefix);
            System.out.println(prefix);
            return;
        }

        for(int i = 0; i<characters.length(); i++)
        {
            char c = characters.charAt(i);
            String rem = characters.substring(0, i) + characters.substring(i+1);
            printPermutations(rem, prefix + c, set);
        }
    }

    public static void main(String[] args) {
        Question8 q8 = new Question8();
        q8.getPermutations("test");
    }
}
