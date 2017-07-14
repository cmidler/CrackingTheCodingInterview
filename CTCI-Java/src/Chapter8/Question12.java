package Chapter8;

/**
 * Created by cmidler on 7/13/17.
 * Eight Queens: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board
 so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all
 diagonals, not just the two that bisect the board.
 */
import java.util.HashSet;
import java.util.ArrayList;
public class Question12 {

    class Queen{
        int row;
        int col;
    }

    void eightQueens()
    {
        int rLen = 8;
        int cLen = 8;
        eightQueens(0, 0, rLen, cLen, new ArrayList<Queen>());
    }

    void eightQueens(int r, int c, int rLen, int cLen, ArrayList<Queen> queens)
    {
        if (queens.size() == rLen)
        {
            System.out.print('[');
            for(Queen q: queens)
                System.out.print('(' + Integer.toString(q.row) + ',' + Integer.toString(q.col) +"), ");
            System.out.print("]\n");

            return;
        }

        if(r>rLen || c>=cLen)
            return;



        for(int i = r; i< rLen; i++)
        {
            for(int j = 0; j< cLen; j++) {
                Queen q = new Queen();
                q.row = i;
                q.col = j;

                if (canInsertQueen(q, queens, rLen, cLen)) {
                    queens.add(q);
                    eightQueens(i+1, j, rLen, cLen, queens);
                    queens.remove(q);
                }

            }

        }
    }

    boolean canInsertQueen(Queen q, ArrayList<Queen> queens, int rLen, int cLen)
    {
        for(Queen queen: queens)
        {
            if (q.row == queen.row || q.col == queen.col)
                return false;
        }

        for(int i = q.row, j=q.col; i<rLen && j<cLen; i++, j++)
        {
            for(Queen queen:queens)
                if(queen.row == i && queen.col == j)
                    return false;
        }

        for(int i = q.row, j=q.col; i>=0 && j<cLen; i--, j++)
        {
            for(Queen queen:queens)
                if(queen.row == i && queen.col == j)
                    return false;
        }

        for(int i = q.row, j=q.col; i<rLen && j>=0; i++, j--)
        {
            for(Queen queen:queens)
                if(queen.row == i && queen.col == j)
                    return false;
        }

        for(int i=q.row, j=q.col; i>=0 && j>=0; i--, j--)
        {
            for(Queen queen:queens)
                if(queen.row == i && queen.col == j)
                    return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Question12 q12 = new Question12();
        q12.eightQueens();
    }
}
