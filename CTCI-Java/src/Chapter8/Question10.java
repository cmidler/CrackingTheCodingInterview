package Chapter8;

/**
 * Created by cptmidler on 7/13/17.
 * Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.
 That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color,
 fill in the surrounding area until the color changes from the original color.
 */
import java.util.Random;
public class Question10 {
    void paintFill(int[][] matrix, int r, int c, int newColor)
    {
        if(matrix == null)
            return;
        int rowLength = matrix.length;
        if (rowLength == 0)
            return;
        int colLength = matrix[0].length;
        if (colLength ==0)
            return;

        if (r <0 || r >= rowLength || c <0 || c >=colLength)
            return;

        int oldColor = matrix[r][c];
        if (oldColor == newColor)
            return;

        fillPaint(matrix, r,c,oldColor,newColor);

    }
    void fillPaint(int[][] matrix, int r, int c, int oldColor, int newColor)
    {

        if (r < 0 || r == matrix.length || c < 0 || c == matrix[0].length || matrix[r][c] != oldColor)
            return;

        matrix[r][c] = newColor;
        fillPaint(matrix, r+1, c, oldColor, newColor);
        fillPaint(matrix, r-1, c, oldColor, newColor);
        fillPaint(matrix, r, c+1, oldColor, newColor);
        fillPaint(matrix, r, c-1, oldColor, newColor);

    }

    public static void main(String[] args) {
        Question10 q10 = new Question10();
        int[][] matrix = new int[8][10];
        Random r = new Random();

        for(int i = 0; i<8; i++) {
            for(int j = 0; j<10; j++)
            {
                matrix[i][j] = r.nextInt(3);
            }
        }

        int randomValue = r.nextInt(3);
        if (randomValue == matrix[4][5])
            randomValue = (randomValue+1)%3;

        System.out.println(matrix[4][5]);
        for(int i = 0; i<8; i++) {
            System.out.print("{");
            for(int j = 0; j<10; j++)
            {
                System.out.print(matrix[i][j]+", ");
            }
            System.out.print("}\n");
        }
        System.out.println();

        q10.paintFill(matrix,4,5,randomValue);
        System.out.println(matrix[4][5]);
        for(int i = 0; i<8; i++) {
            System.out.print("{");
            for(int j = 0; j<10; j++)
            {
                System.out.print(matrix[i][j]+", ");
            }
            System.out.print("}\n");
        }
        System.out.println();
    }
}
