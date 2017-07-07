package Chapter2;

/**
 * Created by cmidler on 7/7/17.
 * Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
 */
public class Question2 {
    private static class Node{
        Node next;
        int data;
    }

    public Node kthToLast(Node head, int k){
        if (head.next == null) {
            if (k == 1)
                return head;
            else
                return null;
        }

        if(k<=0)
            return null;

        Node ptr = head;
        int totalNodes = 0;
        if (ptr.next == null)
            totalNodes = 1;
        while(ptr!=null)
        {
            totalNodes++;
            ptr = ptr.next;
        }

        if (totalNodes < k)
            return null;

        int targetNode = totalNodes-k;
        int count = 0;
        ptr = head;
        while(ptr!=null)
        {
            if (targetNode == count)
                return ptr;
            ptr = ptr.next;
            count++;
        }
        return ptr;

    }

    public static void main(String[] args) {
        Question2 q2 = new Question2();

        Node n5 = new Node();
        n5.data = 5;
        n5.next = null;

        Node n4 = new Node();
        n4.data = 4;
        n4.next = n5;

        Node n3 = new Node();
        n3.data = 3;
        n3.next = n4;

        Node n2 = new Node();
        n2.data = 2;
        n2.next = n3;

        Node n1 = new Node();
        n1.data = 1;
        n1.next = n2;

        Node head = new Node();
        head.data = 0;
        head.next = n1;

        Node k = q2.kthToLast(head, 3);
        System.out.println(k.data);

    }
}
