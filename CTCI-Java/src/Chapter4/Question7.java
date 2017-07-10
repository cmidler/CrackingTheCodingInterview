package Chapter4;

/**
 * Created by cptmidler on 7/10/17.
 * Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
 projects, where the second project is dependent on the first project). All of a project's dependencies
 must be built before the project is. Find a build order that will allow the projects to be built. If there
 is no valid build order, return an error.
 EXAMPLE
 Input:
 projects: a, b, c, d, e, f
 dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
 Output: f, e, a, b, d, c
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;
import java.util.HashSet;
public class Question7 {

    private HashMap<Character, ArrayList<Character>> mapDependencies(char[] projects, char[][]dependencies)
    {
        HashMap<Character, ArrayList<Character>> map = new HashMap<Character, ArrayList<Character>>();
        for(char c: projects)
        {
            ArrayList<Character> deps = new ArrayList<Character>();
            map.put(c,deps);
            for (char[] d:dependencies)
            {
                if(d[1] == c)
                    deps.add(d[0]);
            }
        }
        return map;
    }

    private boolean finishProject(Stack<Character> stack, HashMap<Character,
            ArrayList<Character>> dependencies, HashSet<Character> completed, HashSet<Character> inStack) {

        for (char d : dependencies.get(stack.peek())) {
            if (completed.contains(d))
                continue;
            if (inStack.contains(d))
                return false;
            stack.push(d);
            inStack.add(d);
            if (!finishProject(stack, dependencies, completed, inStack))
                return false;
        }
        while (!stack.empty())
        {
            char top = stack.pop();
            completed.add(top);
            System.out.print(top + ", ");
        }
        return true;
    }

    public void buildOrder(char[] projects, char[][] dependencies) throws Exception
    {

        HashMap<Character, ArrayList<Character>> map = mapDependencies(projects, dependencies);
        HashSet<Character> completed = new HashSet<Character>();
        HashSet<Character> inStack = new HashSet<Character>();
        Stack<Character> stack = new Stack();
        for (char p:projects){
            if(completed.contains(p))
                continue;
            stack.push(p);
            if (!finishProject(stack, map, completed, inStack))
                throw new Exception("Cannot build project " + p);

        }
    }

    public static void main(String[] args) {
        Question7 q7 = new Question7();

        char[] projects = {'a','b','c','d','e','f'};
        char[][] dependencies = {{'a','d'},{'f', 'b'}, {'b','d'}, {'f','a'}, {'d','c'}};
        try{
            q7.buildOrder(projects, dependencies);
        }catch (Exception e){System.out.println(e);};

        dependencies = new char[][]{{'a','d'},{'f', 'b'}, {'b','d'}, {'f','a'}, {'d','c'}, {'d','f'}};

        try{
            q7.buildOrder(projects, dependencies);
        }catch (Exception e){System.out.println(e);};

    }
}
