package Chapter8;

/**
 * Created by cmidler on 7/13/17.
 * Stack of Boxes: You have a stack of n boxes, with widths Wi ' heights hi ' and depths di . The boxes
 cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly
 larger than the box above it in width, height, and depth. Implement a method to compute the
 height of the tallest possible stack. The height of a stack is the sum of the heights of each box.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Collections;
import java.util.Random;

public class Question13 {

    public static class Box implements Comparable<Box> {
        Integer width;
        Integer height;
        Integer depth;

        public int compareTo(Box other)
        {
            return height.compareTo(other.height);
        }
    }

    int maxHeight(ArrayList<Box> boxes)
    {
        Collections.sort(boxes);
        int maxHeight = 0;
        HashMap<Integer, Integer> hashmap = new HashMap<Integer, Integer>();
        for(int i = 0; i< boxes.size(); i++)
        {
            int height = getHeight(i, boxes, hashmap);
            maxHeight = Math.max(height, maxHeight);
        }

        return maxHeight;
    }

    int getHeight(int index, ArrayList<Box> boxes, HashMap<Integer,Integer> hashMap)
    {
        if(index < boxes.size() && hashMap.containsKey(index))
        {
            return boxes.get(index).height;
        }

        Box bottom = boxes.get(index);
        int maxHeight = 0;

        for(int i = 0; i< boxes.size(); i++)
        {
            if(canStack(bottom, boxes.get(i))) {
                maxHeight =  Math.max(getHeight(i, boxes, hashMap), maxHeight);
            }
        }

        maxHeight+=bottom.height;
        hashMap.put(index, maxHeight);
        return maxHeight;
    }

    boolean canStack(Box b1, Box b2)
    {
        if(b1.depth > b2.depth && b1.width > b2.width && b1.height > b2.height)
        {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Question13 q13 = new Question13();
        ArrayList<Box> boxes = new ArrayList<Box>();
        ArrayList<Box> tmpBoxes = new ArrayList<Box>();
        Random r = new Random();
        for(int i = 0; i<20; i++)
        {
            Box b = new Box();
            b.height = r.nextInt(10);
            b.width = r.nextInt(6);
            b.depth = r.nextInt(5);
            boxes.add(b);
            tmpBoxes.add(b);
        }

        Collections.sort(tmpBoxes);
        for(Box b:tmpBoxes)
        {
            System.out.println("Box: " + b.height.toString() + ", " + b.depth.toString() + ", " + b.width.toString());
        }

        System.out.println(q13.maxHeight(boxes));
    }

}
