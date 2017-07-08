package Chapter2;

/**
 * Created by cmidler on 7/8/17.
 * Palindrome: Implement a function to check if a linked list is a palindrome.
 */
public class Question6 {
    private static class Node{
        Node next;
        char c;
    }

    public boolean isLLPal(Node head){
        Node ptr = head;
        Node rev = null;
        int count = 0;
        while(ptr!=null)
        {
            Node node = new Node();
            node.c = ptr.c;
            if(rev == null) {
                node.next = null;
            }
            else
            {
                node.next = rev;
            }
            rev = node;
            ptr = ptr.next;
            count++;
        }
        return isEqual(head, rev, count);
    }

    private boolean isEqual(Node head, Node rev, int count)
    {
        for(int i = 0; i< count/2; i++)
        {
            if (head.c != rev.c)
                return false;
            head = head.next;
            rev = rev.next;
        }
        return true;
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
        Question6 q6 = new Question6();

        Node n6 = new Node();
        n6.c = 1;
        n6.next = null;

        Node n5 = new Node();
        n5.c = 2;
        n5.next = n6;

        Node n4 = new Node();
        n4.c = 3;
        n4.next = n5;

        Node n3 = new Node();
        n3.c = 4;
        n3.next = n4;

        Node n2 = new Node();
        n2.c = 3;
        n2.next = n3;

        Node n1 = new Node();
        n1.c = 2;
        n1.next = n2;

        Node head = new Node();
        head.c = 1;
        head.next = n1;

        q6.printLL(head);
        System.out.println(q6.isLLPal(head));

    }
}
