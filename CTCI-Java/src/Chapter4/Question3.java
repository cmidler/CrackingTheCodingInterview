package Chapter4;

import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * Created by cmidler on 7/9/17.
 * List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
 at each depth (e.g., if you have a tree with depth 0, you'll have 0 linked lists).
 */
public class Question3 {
    private static class TNode{
        TNode left;
        TNode right;
        char data;

        public TNode(char data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private static class LLNode{
        LLNode next;
        TNode tnode;
    }

    private void traverseTree(TNode root, int depth, ArrayList<LLNode> list)
    {
        LLNode n = new LLNode();
        n.tnode = root;
        if(list.size()<depth)
        {
            n.next = null;
            list.add(n);
        }
        else
        {
            n.next = list.get(depth-1);
            list.set(depth-1, n);
        }
        if(root.left!=null)
            traverseTree(root.left, depth+1, list);
        if (root.right!=null)
            traverseTree(root.right, depth+1, list);
    }

    public static void main(String[] args) {
        Question3 q3 = new Question3();

        TNode t1 = new TNode('A');
        TNode t2 = new TNode('B');
        TNode t3 = new TNode('C');
        TNode t4 = new TNode('D');
        TNode t5 = new TNode('E');
        TNode t6 = new TNode('F');

        t1.left = t2;
        t1.right = t3;
        t2.left = t4;
        t4.left = t5;
        t4.right = t6;

        ArrayList<LLNode> list = q3.listOfDepths(t1);

        for(LLNode n: list)
        {
            while (n != null) {
                System.out.print(n.tnode.data + ", ");
                n = n.next;
            }
            System.out.println();
        }


    }

    public ArrayList<LLNode> listOfDepths(TNode root)
    {
        ArrayList<LLNode> list = new ArrayList<LLNode>();
        traverseTree(root, 1, list);
        return list;
    }
}
