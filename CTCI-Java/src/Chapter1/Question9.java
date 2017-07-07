package Chapter1;

/**
 * Created by cmidler on 7/7/17.
 * String Rotation: Assume you have a method isSubstring which checks if one word is a substring
 of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one
 call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
 */
public class Question9 {
    private boolean isSubstring(String s1, String s2)
    {
        return s2.contains(s1);
    }

    public boolean isRotation(String s1, String s2)
    {
        if (s1.length()!=s2.length())
            return false;
        String longString = s1+s1;
        return isSubstring(s2, longString);

    }

    public static void main(String[] args) {
        Question9 q9 = new Question9();
        System.out.println(q9.isRotation("waterbottle","erbottlewat"));
        System.out.println(q9.isRotation("boo","scared"));
        System.out.println(q9.isRotation("waterwater","waterretaw"));
    }
}


