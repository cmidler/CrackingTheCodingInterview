package Chapter10;

/**
 * Created by cmidler on 7/15/17.
 * Missing Int: Given an input file with four billion non-negative integers, provide an algorithm to
 generate an integer that is not contained in the file. Assume you have 1 GB of memory available for
 this task.
 FOLLOW UP
 What if you have only 10MB of memory? Assume that all the values are distinct and we now have
 no more than one billion non-negative integers.
 */
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Question7 {
    public static void main(String[] args) throws FileNotFoundException {
        FileReader fr = new FileReader("filename.txt");
        BufferedReader br = new BufferedReader(fr);

    }


}
