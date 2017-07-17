package Chapter16;

import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by cptmidler on 7/17/17.
 * Master Mind: The Game of Master Mind is played as follows:
 The computer has four slots, and each slot will contain a ball that is red (R), yellow (V), green (G) or
 blue (B). For example, the computer might have RGGB (Slot #1 is red, Slots #2 and #3 are green, Slot
 #4 is blue).
 You, the user, are trying to guess the solution. You might, for example, guess YRGB.
 When you guess the correct color for the correct slot, you get a "hit:' If you guess a color that exists
 but is in the wrong slot, you get a "pseudo-hit:' Note that a slot that is a hit can never count as a
 pseudo-hit.
 For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudo-hit.
 Write a method that, given a guess and a solution, returns the number of hits and pseudo-hits.
 */
public class Question15 {
    class Ball{
        char color;
    }

    String guess(Ball[] balls, String guess)
    {
        if (balls == null || balls.length!=4)
            return "Game broken";

        HashSet<Integer> hitPositions = new HashSet<Integer>();
        HashMap<Character, Integer> notHits = new HashMap<Character, Integer>();
        int pseudo = 0;
        for(int i = 0; i<balls.length; i++){
            char c = balls[i].color;
            if(c == guess.charAt(i))
                hitPositions.add(i);
            else
            {
                if(!notHits.containsKey(c))
                {
                    notHits.put(c, 0);
                }
                notHits.put(c, notHits.get(c)+1);
            }
        }

        for(int i = 0; i<balls.length; i++)
        {
            if(!hitPositions.contains(i))
            {
                char c = guess.charAt(i);
                if (notHits.containsKey(c) && notHits.get(c) > 0)
                {
                    pseudo++;
                    notHits.put(c, notHits.get(c)-1);
                }
            }
        }

        return Integer.toString(hitPositions.size()) + "hits and " + Integer.toString(pseudo) + " pseudo-hits";

    }
}
