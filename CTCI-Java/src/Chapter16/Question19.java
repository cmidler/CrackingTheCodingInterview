package Chapter16;

import java.util.HashSet;

/**
 * Created by cptmidler on 7/17/17.
 * Pond Sizes: You have an integer matrix representing a plot of land, where the value at that location
 represents the height above sea level. A value of zero indicates water. A pond is a region of
 water connected vertically, horizontally, or diagonally. The size of the pond is the total number of
 connected water cells. Write a method to compute the sizes of all ponds in the matrix.
 EXAMPLE
 Input:
 0 2 1 0
 0 1 0 1
 1 1 0 1
 0 1 0 1
 Output: 2, 4, 1 (in any order)
 */
public class Question19 {

    class Location{
        int r;
        int c;

        public Location(int r, int c)
        {
            this.r = r;
            this.c = c;
        }
    }
    HashSet<Integer> getPondSize(int[][] matrix)
    {
        if (matrix == null || matrix.length ==0 || matrix[0].length == 0)
            return null;

        int rowLength = matrix.length;
        int colLength = matrix[0].length;
        HashSet<Location> visited = new HashSet<Location>();
        HashSet<Integer> sizes = new HashSet<Integer>();

        for(int r = 0; r<rowLength; r++)
        {
            for(int c = 0; c<colLength; c++)
            {
                Location l = new Location(r,c);

                if (visited.contains(l))
                    continue;

                int val = matrix[r][c];
                visited.add(l);
                if(val == 0)
                {
                    int size = 1 +pondSize(matrix, r, c + 1, visited)+pondSize(matrix, r + 1, c, visited)+pondSize(matrix, r + 1, c + 1, visited);
                    sizes.add(size);
                }

            }

        }

        if(sizes.size() == 0)
            return null;
        return sizes;
    }

    int pondSize(int[][] matrix, int r, int c, HashSet<Location> visited)
    {
        Location l = new Location(r,c);
        if (visited.contains(l) || r>= matrix.length-1 || c >= matrix[0].length-1)
            return 0;

        visited.add(l);

        int size = 0;
        int val = matrix[r][c];
        if(val == 0)
            size++;
        return size + pondSize(matrix, r, c + 1, visited)+pondSize(matrix, r + 1, c, visited)+pondSize(matrix, r+1, c+1, visited);
    }



}
