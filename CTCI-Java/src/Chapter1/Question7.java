package Chapter1;

/**
 * Created by cmidler on 7/7/17.
 * Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
 bytes, write a method to rotate the image by 90 degrees. can you do this in place?
 */
public class Question7 {
    public void rotateMatrix(int[][]arr, int n)
    {
        if (n == 1)
            return;
        int mid = n/2;
        for(int i =0; i<mid; i++)
        {
            //System.out.println(i);
            int size = n-i*2 - n%2+1;
            int j,k,m,a = 0;
            int [] tmp = new int[size];
            for(j=i; j<n-i-1; j++)
                tmp[j-i] = arr[i][j];
            for(k=i; k<n-i-1;k++)
            {
                int val = arr[k][j];
                arr[k][j] = tmp[k-i];
                tmp[k-i] = val;
            }
            for(m=n-i-1;m>i;m--)
            {
                //System.out.println(m);
                int val = arr[k][m];
                arr[k][m] = tmp[n-m-i-1];
                tmp[n-m-i-1] = val;
            }
            for(a=n-i-1;a>i;a--)
            {
                int val = arr[a][m];
                arr[a][m] = tmp[n-a-i-1];
                tmp[n-a-i-1] = val;
            }
            for(j=i; j<n-i-1;j++)
                arr[i][j] = tmp[j-i];

        }
    }

    public void initMatrix(int[][] matrix, int n) {
        int count = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = count++;
            }
    }

    public void printMatrix(int[][] matrix, int n){
        for(int i =0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(Integer.toString(matrix[i][j])+", ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Question7 q7 = new Question7();

        int[][] matrix = new int[5][5];
        q7.initMatrix(matrix,5);
        q7.rotateMatrix(matrix,5);
        q7.printMatrix(matrix,5);

        matrix = new int[3][3];
        q7.initMatrix(matrix,3);
        q7.rotateMatrix(matrix,3);
        q7.printMatrix(matrix,3);

        matrix = new int[6][6];
        q7.initMatrix(matrix,6);
        q7.rotateMatrix(matrix,6);
        q7.printMatrix(matrix,6);

    }
}
