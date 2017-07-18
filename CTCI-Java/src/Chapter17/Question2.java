package Chapter17;

import java.util.Random;

/**
 * Created by cmidler on 7/17/17.
 * Shuffle: Write a method to shuffle a deck of cards. It must be a perfect shuffle-in other words, each
 of the 52! permutations of the deck has to be equally likely. Assume that you are given a random
 number generator which is perfect.
 */
public class Question2 {
    class Card{
        int number;
        char suit;

        public Card(int number, char suit)
        {
            this.number = 0;
            this.suit = suit;
        }
    }

    void shuffle(Card[] cards)
    {
        Random r = new Random();
        int numCards = cards.length;
        for(int i =0; i< numCards; i++)
        {
            int c = r.nextInt(i);
            Card tmp = cards[c];
            cards[c] = cards[i];
            cards[i] = tmp;
        }
    }
}
