package Chapter3;

/**
 * Created by cmidler on 7/14/17.
 * Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
 an additional temporary stack, but you may not copy the elements into any other data structure
 (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
 */
import java.util.Random;
import java.util.Stack;
public class Question5 {
    void sortStack(Stack<Integer> stack)
    {
        if(stack == null || stack.size() <=1)
            return;

        Stack<Integer> buffer = new Stack<Integer>();
        while(!stack.isEmpty())
        {
            int val = stack.pop();
            if(buffer.isEmpty() || buffer.peek() <= val)
                buffer.push(val);
            else
            {
                int numPopped = 0;
                while(!buffer.isEmpty())
                {
                    if(buffer.peek()<=val)
                        break;
                    numPopped++;
                    stack.push(buffer.pop());
                }
                buffer.push(val);
                for(int i =0; i< numPopped; i++)
                    buffer.push(stack.pop());
            }
        }

        while(!buffer.isEmpty())
            stack.push(buffer.pop());
    }

    public static void main(String[] args) {
        Question5 q5 = new Question5();
        Stack<Integer> stack = new Stack<Integer>();
        Random r = new Random();
        for(int i = 0; i<10; i++) {
            int val = r.nextInt(100);
            stack.push(val);
            System.out.println(val);
        }
        System.out.println("\n");

        q5.sortStack(stack);

        while(!stack.isEmpty())
            System.out.println(stack.pop());
    }
}
