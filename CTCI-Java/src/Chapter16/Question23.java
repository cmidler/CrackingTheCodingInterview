package Chapter16;

import java.util.Random;

/**
 * Created by cmidler on 7/17/17.
 * Rand7 from Rand5: Implement a method rand7() given rand5 (). That is, given a method that
 generates a random number between 0 and 4 (inclusive), write a method that generates a random
 number between 0 and 6 (inclusive).
 */
public class Question23 {
    int rand5(){
        Random random = new Random();
        return random.nextInt(5);
    }

    int rand7(){
        while (true)
        {
            int r = 5*rand5() + rand5();
            if(r<21)
                return r%7;
        }
    }
}
