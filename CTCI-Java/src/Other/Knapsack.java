package Other;

import java.util.Comparator;
import java.util.Arrays;
import java.util.HashMap;

/**
 * Created by cptmidler on 7/18/17.
 * Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in
 * the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and
 * weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out
 * the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You
 * cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 */

public class Knapsack {

    class Item implements Comparable<Item>{
        int weight;
        int value;

        public int compareTo(Item i)
        {
            return this.weight-i.weight;
        }
    }

    Item[] getItemsArray(int[] weights, int[] values)
    {
        Item[] items = new Item[weights.length];
        for(int i = 0; i<weights.length; i++)
        {
            Item item = new Item();
            item.weight = weights[i];
            item.value = values[i];
            items[i] = item;
        }

        Arrays.sort(items);
        return items;
    }

    int getMaxVal(int[] weights, int[] vals, int w)
    {
        if(weights == null || vals == null || weights.length<=0 || weights.length != vals.length || w<0)
            return -1;

        Item[] items = getItemsArray(weights, vals);
        HashMap<Item, Integer> itemValue = new HashMap<Item, Integer>();
        return maxVal(items, w, 0, 0, itemValue);
    }

    int maxVal(Item[] items, int w, int index, int currentWeight, HashMap<Item, Integer> itemValue)
    {
        if(index == items.length || currentWeight >=w)
            return 0;

        if(itemValue.containsKey(items[index]))
            return itemValue.get(items[index]);

        int currentVal = items[index].value;
        int weight = items[index].weight;

        if(currentWeight+weight>w)
            return 0;

        itemValue.put(items[index], Math.max(currentVal + maxVal(items, w, index + 1, currentWeight + weight, itemValue), maxVal(items, w, index + 1, currentWeight, itemValue)));
        return itemValue.get(items[index]);
    }

    public static void main(String[] args) {

        Knapsack k = new Knapsack();
        int[] values = new int[] {894, 260, 392, 281, 27};
        int[] weights = new int[] {8, 6, 4, 0, 21};
        int W = 30;

        System.out.println(k.getMaxVal(weights, values, W));
    }

}
