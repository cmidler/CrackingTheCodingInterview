package Chapter10;

/**
 * Created by cmidler on 7/14/17.
 * Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to
 each other.
 */
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.ArrayList;
public class Question2 {

    class AnagramComparator implements Comparator<String> {


        public int compare(String s1, String s2) {
            return sortChars(s1).compareTo(sortChars(s2));
        }
    }

    public String sortChars(String s1) {
        char[] c = s1.toCharArray();
        Arrays.sort(c);
        return new String(c);
    }

    void sortArrayOfStrings(String[] strings)
    {
        HashMap<String, ArrayList<String>> hm = new HashMap<String, ArrayList<String>>();
        for(String s: strings)
        {
            String key = sortChars(s);
            if(!hm.containsKey(key)) {
                ArrayList<String> stringList = new ArrayList<String>();
                hm.put(key, stringList);
            }
            ArrayList<String> stringList = hm.get(key);
            stringList.add(s);
            hm.put(key, stringList);
        }

        int i = 0;
        for (String key: hm.keySet())
        {
            ArrayList<String> stringList = hm.get(key);
            for(String s:stringList)
                strings[i++] = s;

        }
    }




    public static void main(String[] args) {
        Question2 q2 = new Question2();
        String[] strings = {"testing", "strings", "ok", "let", "gsinrts", "ko", "tel"};
        q2.sortArrayOfStrings(strings);
        for(String s: strings)
            System.out.println(s);

    }
}
