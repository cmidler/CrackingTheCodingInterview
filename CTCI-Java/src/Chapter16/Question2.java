package Chapter16;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

/**
 * Created by cmidler on 7/15/17.
 * Word Frequencies: Design a method to find the frequency of occurrences of any given word in a
 book. What if we were running this algorithm multiple times?
 */
public class Question2 {

    HashMap<String, Integer> populateHashMap(String filename) throws FileNotFoundException, IOException
    {
        FileReader fr = new FileReader(filename);
        BufferedReader br = new BufferedReader(fr);
        HashMap<String, Integer> hm = new HashMap();
        String line = null;
        while((line=br.readLine())!=null)
        {
            StringBuilder s = new StringBuilder();
            for(int i =0; i<line.length(); i++)
            {
                char c = line.charAt(i);
                if(Character.isLetter(c))
                {
                    s.append(c);
                }
                else
                {
                    addStringToHashmap(hm, s.toString());
                    s = new StringBuilder();
                }
            }

            if(s.length()!=0)
                addStringToHashmap(hm, s.toString());
        }
        return hm;
    }

    void addStringToHashmap(HashMap<String,Integer> hm, String s)
    {
        if(!hm.containsKey(s))
            hm.put(s, 0);
        hm.put(s,hm.get(s)+1);
    }

    int getOccurences(HashMap<String, Integer> hm, String word)
    {
        if(hm.containsKey(word))
            return hm.get(word);
        return 0;
    }
}
