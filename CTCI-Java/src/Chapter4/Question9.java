package Chapter4;

import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * Created by cmidler on 7/10/17.
 * BST Sequences: A binary search tree was created by traversing through an array from left to right
 and inserting each element. Given a binary search tree with distinct elements, print all possible
 arrays that could have led to this tree.
 */
public class Question9 {

    private static class Node{
        Node left;
        Node right;
        Integer data;

        public Node(Integer data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    ArrayList<ArrayList<Integer>> getAllSequences(Node root)
    {
        ArrayList<ArrayList<Integer>> results = new ArrayList<ArrayList<Integer>>();
        if (root == null)
        {
            results.add(new ArrayList<Integer>());
            return results;
        }

        ArrayList<Integer> prefix = new ArrayList<Integer>();
        prefix.add(root.data);

        ArrayList<ArrayList<Integer>> left = getAllSequences(root.left);
        ArrayList<ArrayList<Integer>> right = getAllSequences(root.right);
        for(ArrayList<Integer> l:left)
        {
            for (ArrayList<Integer> r:right)
            {
                ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
                weaveLists(l,r,res,prefix);
                results.addAll(res);
            }
        }
        return results;

    }





    private void weaveLists(ArrayList<Integer> list1, ArrayList<Integer> list2,
                           ArrayList<ArrayList<Integer>> results, ArrayList<Integer> current){

        if (list1.isEmpty() || list2.isEmpty())
        {
            current.addAll(list1);
            current.addAll(list2);
            results.add(new ArrayList<Integer>(current));
            current.removeAll(list1);
            current.removeAll(list2);
            return;
        }

        Integer first = list1.get(0);
        current.add(first);
        int length = list1.size();
        ArrayList<Integer> sublist = new ArrayList<Integer>();
        if (length > 1)
            sublist = new ArrayList<Integer>(list1.subList(1,length));

        weaveLists(sublist, list2, results, current);
        current.remove(first);

        first = list2.get(0);
        current.add(first);
        length = list2.size();
        sublist = new ArrayList<Integer>();
        if(length >1)
            sublist = new ArrayList<Integer>(list2.subList(1, length));
        weaveLists(list1, sublist, results, current);
        current.remove(first);

    }

    public static void main(String[] args) {
        Question9 q9 = new Question9();
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
        ArrayList<ArrayList<Integer>> test = q9.getAllSequences(t3);
        System.out.println(test);

    }
}
