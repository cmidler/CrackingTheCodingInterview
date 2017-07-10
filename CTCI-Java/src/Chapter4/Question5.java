package Chapter4;

/**
 * Created by cmidler on 7/9/17.
 * Validate BST: Implement a function to check if a binary tree is a binary search tree.
 */
public class Question5 {
    private static class Node{
        Node left;
        Node right;
        int data;

        public Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private int checkLeft(Node root, int val, int origRootVal)
    {
        if(root == null) return val;
        if(root.data > val) return origRootVal+1;

        int left = checkLeft(root.left, root.data, origRootVal);
        int right = checkRight(root.right, root.data, origRootVal);
        return Math.max(left, right);

    }

    private int checkRight(Node root, int val, int origRootVal)
    {
        if(root == null) return val;
        if(root.data <= val) return origRootVal-1;
        int left = checkLeft(root.left, root.data, origRootVal);
        int right = checkRight(root.right, root.data, origRootVal);
        return Math.min(left,right);
    }

    public boolean isBST(Node root){
        if(root == null) return true;
        if ((root.data >=checkLeft(root.left,root.data,root.data)) && (root.data<checkRight(root.right, root.data, root.data)))
            return true;
        return false;
    }

    public static void main(String[] args) {
        Question5 q5 = new Question5();

        Node t1 = new Node(1);
        Node t2 = new Node(2);
        Node t3 = new Node(3);
        Node t4 = new Node(4);
        Node t5 = new Node(5);
        Node t6 = new Node(6);

        t3.left = t2;
        t2.left = t1;
        t3.right = t5;
        t5.left = t4;
        t5.right = t6;

        System.out.println(q5.isBST(t3));
        Node t7 = new Node(7);
        t2.right = t7;
        System.out.println(q5.isBST(t3));
    }
}
