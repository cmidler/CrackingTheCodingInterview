package Chapter10;

/**
 * Created by cmidler on 7/15/17.
 * Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish to be able
 to look up the rank of a number x (the number of values less than or equal to x). Implement the data
 structures and algorithms to support these operations. That is, implement the method track (int
 x), which is called when each number is generated, and the method getRankOfNumber(int
 x), which returns the number of values less than or equal to X (not including x itself).
 EXAMPLE
 Stream(inorderofappearance):5, 1,4,4, 5, 9, 7, 13, 3
 getRankOfNumber(1) 0
 getRankOfNumber(3) 1
 getRankOfNumber(4) 3
 */
public class Question10 {
    class Tree {
        Node root;


        class Node {
            Node left;
            Node right;
            int data;
            int lessThan;
        }

        int getRankOfNumber(int x)
        {
            return getRankOfNumber(x, root);
        }

        int getRankOfNumber(int x, Node n)
        {
            if(n.data == x)
                return n.lessThan;
            else if (n.data > x)
                return getRankOfNumber(x, n.right);
            else
                return getRankOfNumber(x,n.left);
        }

        void insertIntoTree(Node n, int x, int biggerThan)
        {
            if(x<=n.data)
            {
                if(n.left == null)
                {
                    Node node = new Node();
                    node.data = x;
                    node.lessThan = biggerThan;
                }
                else
                    insertIntoTree(n.left, x, biggerThan);
            }
            else
            {
                if(n.right == null)
                {
                    Node node = new Node();
                    node.data = x;
                    node.lessThan = biggerThan+n.lessThan;
                }
                else
                    insertIntoTree(n.right, x, biggerThan+n.lessThan);

            }
        }

        void track(int x)
        {
            if( root == null)
            {
                Node n = new Node();
                n.data = x;
                n.lessThan = 0;
            }
            else
                insertIntoTree(root, x, 0);

        }
    }
}
