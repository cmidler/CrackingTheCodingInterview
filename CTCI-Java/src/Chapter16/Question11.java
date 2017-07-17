package Chapter16;

import java.util.HashSet;

/**
 * Created by cmidler on 7/16/17.
 * Diving Board: You are building a diving board by placing a bunch of planks of wood end-to-end.
 There are two types of planks, one of length shorter and one of length longer. You must use
 exactly K planks of wood. Write a method to generate all possible lengths for the diving board.
 */
public class Question11 {
    HashSet<Integer> getBoardLength(int k, int shorter, int longer)
    {
        HashSet<Integer> lengths = new HashSet<Integer>();
        HashSet<String> found = new HashSet<String>();
        if(k<=0 || shorter <=0 || longer <=0)
            return lengths;
        getCombos(k, shorter, longer, lengths, 0, found);
        return lengths;
    }

    void getCombos(int k, int shorter, int longer, HashSet<Integer> lengths, int length,HashSet<String> found)
    {
        if(k == 0) {
            lengths.add(length);
            return;
        }

        String key = Integer.toString(k) + ' ' + Integer.toString(length);
        if(found.contains(key))
            return;

        getCombos(k-1, shorter, longer, lengths, shorter+length, found);
        getCombos(k-1, shorter, longer, lengths, longer+length,found);
        found.add(key);
    }
}
