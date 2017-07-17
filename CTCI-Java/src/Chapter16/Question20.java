package Chapter16;

import java.util.ArrayList;
import java.util.HashMap;
/**
 * Created by cptmidler on 7/17/17.
 * T9: On old cell phones, users typed on a numeric keypad and the phone would provide a list of
 words that matched these numbers. Each digit mapped to a set of 0 - 4 letters. Implement an algorithm
 to return a list of matching words, given a sequence of digits. You are provided a list of valid
 words (provided in whatever data structure you'd like)
 */
public class Question20 {
    class Node{
        char c;
        HashMap<Character, Node> nodes;

        Node getNode(char c)
        {
            if(nodes.containsKey(c))
                return nodes.get(c);
            return null;
        }
    }

    ArrayList<String> getWords(Node node, String digits){
        if(node == null || digits == null || digits.length() == 0)
            return null;
        ArrayList<String> words = new ArrayList<String>();

        getValidWords(node, 0, digits, "", words);
        return words;
    }

    void getValidWords(Node node, int index, String digits, String prefix, ArrayList<String> words)
    {
        if(index == digits.length())
        {
            words.add(prefix);
            return;
        }



        for(int i = index; i<digits.length(); i++)
        {
            char[] letters = getCharsFromDigit(digits.charAt(i));
            for(int j = 0; j<letters.length; j++)
            {
                char letter = letters[j];
                if(node.getNode(letter) !=null)
                {
                    getValidWords(node.getNode(letter), index+1, digits,prefix+letter, words );
                }
            }
        }
    }

    char[] getCharsFromDigit(char digit)
    {
        switch(digit){
            case '2': return new char[]{'a','b','c'};
            case '3': return new char[]{'d','e','f'};
            case '4': return new char[]{'g','h','i'};
            case '5': return new char[]{'j','k','l'};
            case '6': return new char[]{'m','n','o'};
            case '7': return new char[]{'p','q','r', 's'};
            case '8': return new char[]{'t','u','v'};
            case '9': return new char[]{'w','x','y', 'z'};
            default:return null;
        }
    }

}
