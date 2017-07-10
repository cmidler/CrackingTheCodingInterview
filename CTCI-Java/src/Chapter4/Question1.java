package Chapter4;

/**
 * Created by cmidler on 7/9/17.
 * Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
 route between two nodes.
 */
import java.lang.reflect.Array;
import java.util.ArrayList;
public class Question1 {
    private static class Node{
        String name;
        boolean visited;
        Node[] adj;

        public Node(String name)
        {
            this.name = name;
            visited = false;
        }
    }

    public boolean doesRouteExist(Node n1, Node n2){
        n1.visited = true;
        if (n1 == n2)
            return true;
        System.out.println("Node is " + n1.name + " with list: ");
        for(Node n: n1.adj)
            System.out.print("Node " + n.name +", ");
        System.out.println();
        for(Node n: n1.adj)
        {
            if(!n.visited)
                return doesRouteExist(n,n2);
        }
        return false;
    }

    public void resetVisited(ArrayList<Node> nodes)
    {
        for(Node n: nodes)
            n.visited = false;
    }

    public static void main(String[] args) {
        Question1 q1 = new Question1();
        Node n1 = new Node("n1");
        Node n2 = new Node("n2");
        Node n3 = new Node("n3");
        Node n4 = new Node("n4");
        Node n5 = new Node("n5");
        Node n6 = new Node("n6");
        Node n7 = new Node("n7");

        n1.adj = new Node[]{n2,n3};
        n2.adj = new Node[]{n1,n3};
        n3.adj = new Node[]{n4};
        n4.adj = new Node[]{n2,n5,n6};
        n5.adj = new Node[]{n1,n6};
        n6.adj = new Node[]{};
        n7.adj = new Node[]{n4};

        ArrayList<Node> nodes = new ArrayList<Node>();
        nodes.add(n1);
        nodes.add(n2);
        nodes.add(n3);
        nodes.add(n4);
        nodes.add(n5);
        nodes.add(n6);
        nodes.add(n7);


        System.out.println(q1.doesRouteExist(n1,n2));
        q1.resetVisited(nodes);
        System.out.println(q1.doesRouteExist(n1,n7));
        q1.resetVisited(nodes);
        System.out.println(q1.doesRouteExist(n5,n4));
        q1.resetVisited(nodes);
        System.out.println(q1.doesRouteExist(n6,n1));
        q1.resetVisited(nodes);

    }
}
