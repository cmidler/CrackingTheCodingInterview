package Chapter10;

/**
 * Created by cmidler on 7/15/17.
 * Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in
 ascending order, write a method to find an element.
 */
public class Question9 {
    class Point{
        Integer row;
        Integer col;
    }

    Point find(int[][] matrix, int n)
    {
        int r = 0;
        int c = 0;
        if (matrix == null || matrix.length ==0 || matrix[0].length == 0)
            return null;
        int rLen = matrix.length-1;
        int cLen = matrix[0].length-1;

        if(matrix[rLen][cLen] == n)
        {
            Point p = new Point();
            p.row = rLen;
            p.col = cLen;
            return p;
        }
        while(c != cLen || r!=rLen)
        {
            if(matrix[r][c] == n)
            {
                Point p = new Point();
                p.row = r;
                p.col = c;
                return p;
            }
            else if(c == matrix[0].length-1) {
                r++;
            }
            else if(r == matrix.length-1) {
                c++;
            }
            else{
                if(matrix[r+1][c] < n)
                    r++;
                else
                    c++;
            }
        }

        return null;
    }

    public static void main(String[] args) {
        Question9 q9 = new Question9();
        int [][] matrix = new int[3][4];
        matrix[0][0] = 1;
        matrix[0][1] = 3;
        matrix[0][2] = 3;
        matrix[0][3] = 4;

        matrix[1][0] = 5;
        matrix[1][1] = 7;
        matrix[1][2] = 8;
        matrix[1][3] = 10;

        matrix[2][0] = 12;
        matrix[2][1] = 34;
        matrix[2][2] = 42;
        matrix[2][3] = 49;

        Point p = q9.find(matrix, 7);
        System.out.println(p.row.toString() + " " + p.col.toString());

        p = q9.find(matrix, 42);
        System.out.println(p.row.toString() + " " + p.col.toString());

        p = q9.find(matrix, 4);
        System.out.println(p.row.toString() + " " + p.col.toString());

        p = q9.find(matrix, 11);
        System.out.println(p);

        p = q9.find(matrix, 49);
        System.out.println(p.row.toString() + " " + p.col.toString());

    }
}
