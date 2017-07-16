package Chapter10;

/**
 * Created by cmidler on 7/15/17.
 * Sparse Search: Given a sorted array of strings that is interspersed with empty strings, write a
 method to find the location of a given string.
 EXAMPLE
 Input: ball, {("at", "", "","","ball", "", "", "car", "", "", "dad", "", ""_}
 Output: 4
 */
public class Question5 {

    int binarySearch(String[] sparseArray, int low, int high, String word)
    {
        if(low>high)
            return -1;

        int mid = (high+low)/2;
        String s = sparseArray[mid];

        if(s.equals(word))
            return mid;
        if(s.isEmpty())
        {
            int l = binarySearch(sparseArray, low, mid-1, word);
            int h = binarySearch(sparseArray, mid+1, high, word);
            if (l!= -1)
                return l;
            else if (h!=-1)
                return h;
            else
                return -1;
        }
        else if (word.compareTo(s)<0)
            return binarySearch(sparseArray, low, mid-1, word);
        else
            return binarySearch(sparseArray, mid+1, high, word);


    }



    public static void main(String[] args) {
        Question5 q5 = new Question5();
        String[] strings = {"at", "", "","","ball", "", "", "car", "", "", "dad", "", ""};
        System.out.println(q5.binarySearch(strings,0,strings.length-1, "at"));
        System.out.println(q5.binarySearch(strings,0,strings.length-1, "ball"));
        System.out.println(q5.binarySearch(strings,0,strings.length-1, "car"));
        System.out.println(q5.binarySearch(strings,0,strings.length-1, "dad"));
        System.out.println(q5.binarySearch(strings,0,strings.length-1, "even"));
    }
}
