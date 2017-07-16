package Chapter16;

/**
 * Created by cmidler on 7/15/17.
 * English Int: Given any integer, print an English phrase that describes the integer (e.g., "One Thousand,
 Two Hundred Thirty Four").
 */
public class Question8 {
    String englishInt(int n)
    {
        String num = Integer.toString(n);
        int length = num.length();
        int pos =0;
        char c;
        boolean printMillion = false;
        boolean printThousand = false;
        StringBuilder english = new StringBuilder();
        if (length == 10)//billions
        {

            String s = Character.toString(num.charAt(pos));
            english.append(digitToNum(s) +" Billion ");
        }

        if(length >=9)
        {
            pos = length-9;
            c = num.charAt(pos);
            if(c != '0') {
                printMillion = true;
                String s = Character.toString(c);
                english.append(digitToNum(s) + " Hundred ");
            }
        }

        if(length >=8)
        {
            pos = length-8;
            c = num.charAt(pos);
            if(c != '0') {
                printMillion = true;
                StringBuilder s = new StringBuilder();
                s.append(c);
                s.append('0');
                english.append(digitToNum(s.toString()) + " ");
            }
        }

        if(length >=7)
        {
            pos = length-7;
            c = num.charAt(pos);
            if(c != '0') {
                printMillion = true;
                String s = Character.toString(c);
                english.append(digitToNum(s) + " ");
            }

            if(printMillion)
                english.append("Million ");
        }

        if(length >=6)
        {
            pos = length-6;
            c = num.charAt(pos);
            if(c != '0') {
                printThousand = true;
                String s = Character.toString(c);
                english.append(digitToNum(s) + " Hundred ");
            }
        }

        if(length >=5)
        {
            pos = length-5;
            c = num.charAt(pos);
            if(c != '0') {
                printThousand = true;
                StringBuilder s = new StringBuilder();
                s.append(c);
                s.append('0');
                english.append(digitToNum(s.toString()) + " ");
            }
        }

        if(length >=4)
        {
            pos = length-4;
            c = num.charAt(pos);
            if(c != '0') {
                printThousand = true;
                String s = Character.toString(c);
                english.append(digitToNum(s) + " ");
            }

            if(printThousand)
                english.append("Thousand ");
        }

        if(length >=3)
        {
            pos = length-3;
            c = num.charAt(pos);
            if(c != '0') {
                printThousand = true;
                String s = Character.toString(c);
                english.append(digitToNum(s) + " Hundred ");
            }
        }

        if(length >=2)
        {
            pos = length-2;
            c = num.charAt(pos);
            if(c != '0') {
                printThousand = true;
                StringBuilder s = new StringBuilder();
                s.append(c);
                s.append('0');
                english.append(digitToNum(s.toString()) + " ");
            }
        }

        if(length >=1)
        {
            pos = length-1;
            c = num.charAt(pos);
            if(c != '0') {
                printThousand = true;
                String s = Character.toString(c);
                english.append(digitToNum(s) + " ");
            }
        }



        return english.toString();
    }

    String digitToNum(String n)
    {
        if(n.equals("0")) return "Zero";
        if(n.equals("1")) return "One";
        if(n.equals("2")) return "Two";
        if(n.equals("3")) return "Three";
        if(n.equals("4")) return "Four";
        if(n.equals("5")) return "Five";
        if(n.equals("6")) return "Six";
        if(n.equals("7")) return "Seven";
        if(n.equals("8")) return "Eight";
        if(n.equals("9")) return "Nine";
        if(n.equals("10")) return "Ten";
        if(n.equals("20")) return "Twenty";
        if(n.equals("30")) return "Thirty";
        if(n.equals("40")) return "Forty";
        if(n.equals("50")) return "Fifty";
        if(n.equals("60")) return "Sixty";
        if(n.equals("70")) return "Seventy";
        if(n.equals("80")) return "Eighty";
        if(n.equals("90")) return "Ninety";
        return null;

    }

    public static void main(String[] args) {
        Question8 q8 = new Question8();
        System.out.println(q8.englishInt(1123400682));
    }
}
