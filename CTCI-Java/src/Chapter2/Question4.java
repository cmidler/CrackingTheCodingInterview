package Chapter2;

/**
 * Created by cmidler on 7/7/17.
 * Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
 before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
 to be after the elements less than x (see below). The partition element x can appear anywhere in the
 "right partition"; it does not need to appear between the left and right partitions.
 EXAMPLE

 Input: 3 -> 5 -> 8 -> 5 - > 10 -> 2 -> 1 [partition = 5)
 Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 */
public class Question4 {
    private static class Node{
        Node next;
        int val;
    }

    public Node partitionLL(Node head, int val)
    {
        Node ptr = head;

        Node lower = null;
        Node higher = null;
        Node higherHead = null;
        Node newHead = head;

        while(ptr!=null)
        {
            if (ptr.val < val)
            {
                if(lower == null)
                {
                    newHead = ptr;
                }
                else
                {
                    lower.next = ptr;
                }
                lower = ptr;
            }
            else
            {
               if(higher == null)
               {
                   higherHead = ptr;
               }
               else
               {
                   higher.next = ptr;
               }

               higher = ptr;

            }
            ptr = ptr.next;
        }

        if(lower != null)
            lower.next = higherHead;
        if(higher!=null)
            higher.next = null;

        return newHead;
    }

    public void printLL(Node head)
    {
        while (head!=null)
        {
            System.out.print(Integer.toString(head.val) + " -> ");
            head = head.next;
        }
        System.out.println('\n');
    }

    public static void main(String[] args) {
        Question4 q4 = new Question4();

        Node n6 = new Node();
        n6.val = 1;
        n6.next = null;

        Node n5 = new Node();
        n5.val = 2;
        n5.next = n6;

        Node n4 = new Node();
        n4.val = 10;
        n4.next = n5;

        Node n3 = new Node();
        n3.val = 5;
        n3.next = n4;

        Node n2 = new Node();
        n2.val = 8;
        n2.next = n3;

        Node n1 = new Node();
        n1.val = 5;
        n1.next = n2;

        Node head = new Node();
        head.val = 3;
        head.next = n1;

        q4.printLL(head);
        Node newHead = q4.partitionLL(head,5);
        q4.printLL(newHead);
    }
}
