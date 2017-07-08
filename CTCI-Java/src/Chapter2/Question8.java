package Chapter2;

/**
 * Created by cmidler on 7/8/17.
 * Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
 beginning of the loop.
 DEFINITION
 Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
 as to make a loop in the linked list.
 EXAMPLE
 Input: A -) B -) C -) 0 -) E - ) C[thesameCasearlierl
 Output: C
 */
import java.util.Collection;
import java.util.Iterator;
import java.util.HashSet;
public class Question8 {
    private static class Node{
        Node next;
        char c;
    }

    public Node findLoop(Node head)
    {
        HashSet<Node> set = new HashSet<Node>();
        while(head!=null)
        {
            if (set.contains(head))
                return head;
            else
                set.add(head);
            head =head.next;
        }
        return null;
    }

    public void printLL(Node head)
    {
        while (head!=null)
        {
            System.out.print(Integer.toString(head.c) + " -> ");
            head = head.next;
        }
        System.out.println('\n');
    }

    public static void main(String[] args) {
        Question8 q8 = new Question8();

        Node n2 = new Node();

        Node n5 = new Node();
        n5.c = 'F';
        n5.next = n2;

        Node n4 = new Node();
        n4.c = 'E';
        n4.next = n5;

        Node n3 = new Node();
        n3.c = 'D';
        n3.next = n4;

        n2.c = 'C';
        n2.next = n3;

        Node n1 = new Node();
        n1.c = 'B';
        n1.next = n2;

        Node head = new Node();
        head.c = 'A';
        head.next = n1;

        System.out.println(q8.findLoop(head).c);

    }
}
