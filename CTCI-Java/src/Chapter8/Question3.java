package Chapter8;

/**
 * Created by cmidler on 7/12/17.
 * Magic Index: A magic index in an array A [0 ... n -1] is defined to be an index such that A[ i] =
 i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
 array A.
 FOLLOW UP
 What if the values are not distinct?
 */
public class Question3 {
    int getMagicNumber(int[] array){
        return binarySearch(array, 0, array.length-1);
    }

    int binarySearch(int []array, int low, int high)
    {
        if (low > high)
            return -1;

        int index = (high+low)/2;
        int value = array[index];

        if(value == index)
            return value;
        else if (value < index)
            return binarySearch(array, index+1, high);
        else
            return binarySearch(array, low, index-1);

    }

    int getMagicNumberNotDistinct(int[]array)
    {
        return binarySearch2(array, 0, array.length-1);
    }

    int binarySearch2(int []array, int low, int high)
    {
        if (low > high)
            return -1;

        int index = (high+low)/2;
        int value = array[index];

        if(value == index)
            return value;
        else if (value < index) {
            int below = -1;
            if(value >=low)
                below = binarySearch(array, low, value);
            if (below == -1)
                return binarySearch(array, index + 1, high);
            else
                return below;
        }
        else
        {
            int above = -1;
            if (value <= high){
                above = binarySearch(array, value, high);
            }
            if(above == -1)
                return binarySearch(array, low, index-1);
            else
                return above;
        }


    }
}
