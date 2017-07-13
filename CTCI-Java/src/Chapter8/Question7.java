package Chapter8;

import Chapter1.*;

/**
 * Created by cptmidler on 7/13/17.
 * Permutations without Dups: Write a method to compute all permutations of a string of unique
 characters
 */
public class Question7 {

    void getPermutations(String characters)
    {
        printPermutations(characters, "");
    }

    void printPermutations(String characters, String prefix)
    {
        if(characters.length() == 0) {
            System.out.println(prefix);
            return;
        }

        for(int i = 0; i<characters.length(); i++)
        {
            char c = characters.charAt(i);
            String rem = characters.substring(0, i) + characters.substring(i+1);
            printPermutations(rem, prefix + c);
        }
    }

    public static void main(String[] args) {
        Question7 q7 = new Question7();
        q7.getPermutations("help");
    }
}
