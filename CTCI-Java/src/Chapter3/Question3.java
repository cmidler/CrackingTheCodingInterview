package Chapter3;

/**
 * Created by cmidler on 7/9/17.
 * Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
 threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
 composed of several stacks and should create a new stack once the previous one exceeds capacity.
 SetOfStacks. push () and SetOfStacks. pop() should behave identically to a single stack
 (that is, pop ( ) should return the same values as it would if there were just a single stack).
 FOLLOW UP
 Implement a function popAt (int index) which performs a pop operation on a specific substack.

 */
import Chapter2.Question8;

import java.util.ArrayList;
import java.util.Stack;
public class Question3 {
    public static class SetOfStacks{

        ArrayList<Stack> stacks = new ArrayList();
        private int capacity;
        private int current;
        public SetOfStacks(int capacity)
        {
            this.capacity = capacity;
            this.current =0;
            Stack<Integer> s = new Stack<Integer>();
            stacks.add(s);
        }

        public Stack<Integer> peek()
        {
            if (stacks.isEmpty())
                return null;
            return stacks.get(current);
        }
        public Integer push(int val)
        {

            if (stacks.get(current).size() == capacity) {
                Stack<Integer> s = new Stack<Integer>();
                current++;
                stacks.add(s);
            }
            Stack<Integer> s = peek();
            s.push(val);

            return val;
        }

        public Integer pop()
        {
            Stack<Integer> cur = peek();
            if (cur == null)
                return null;
            while(cur.isEmpty())
            {
                stacks.remove(current);
                current--;
                cur = peek();
                if (cur == null)
                    return null;
            }

            return cur.pop();
        }


        public void printStacks(){
            for(Stack s:stacks)
            {
                for(int i = 0; i<s.size(); i++)
                {
                    System.out.print(s.get(i).toString() + ", ");
                }
                System.out.println("");
            }
            System.out.println("");
        }

    }

    public static void main(String[] args) {
        SetOfStacks stacks = new SetOfStacks(3);
        stacks.push(1);
        stacks.push(1);
        stacks.push(1);
        stacks.push(2);
        stacks.push(2);
        stacks.push(2);
        stacks.printStacks();
        stacks.pop();
        stacks.printStacks();
        stacks.push(-1);
        stacks.printStacks();
        stacks.pop();
        stacks.pop();
        stacks.pop();
        stacks.pop();
        stacks.printStacks();
        stacks.pop();
        stacks.pop();
        stacks.printStacks();




    }
}
