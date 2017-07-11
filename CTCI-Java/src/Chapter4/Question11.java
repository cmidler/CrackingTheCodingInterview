package Chapter4;

import com.sun.source.tree.Tree;

import java.util.Random;

/**
 * Created by cptmidler on 7/11/17.
 * Random Node: You are implementing a binary tree class from scratch which, in addition to
 insert, find, and delete, has a method getRandomNode() which returns a random node
 from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
 for getRandomNode, and explain how you would implement the rest of the methods.

 //may be wrong. Wanted to go through the exercise of writing the code for each method as practice
 */
public class Question11 {
    public static class Node {
        Node left;
        Node right;
        int size;
        int data;

        public Node(int data) {
            this.left = null;
            this.right = null;
            this.data = data;
            this.size = 1;
        }

        public void insert(int d) {
            if (d <= data) {
                if (left == null) {
                    Node newNode = new Node(d);
                    left = newNode;
                } else
                    left.insert(d);
            } else {
                if (right == null) {
                    Node newNode = new Node(d);
                    right = newNode;
                } else
                    right.insert(d);

            }
            size++;
        }

        public Node find(int d) {
            if (data == d) {
                return this;
            }
            else {
                Node ptr = null;
                if (left != null)
                    ptr=left.find(d);
                if (ptr != null)
                    return ptr;
                if(right !=null)
                    ptr=right.find(d);
                if (ptr!=null)
                    return ptr;
                return null;
            }
        }


        private boolean delete(int d, Node parent) {
            size--;
            //check left
            if(d<data) {
                if(left!=null) {
                    return left.delete(d, this);
                }
                else
                    return false;
            }
            else if (d > data ){
                if(right!=null) {
                    return right.delete(d, this);
                }
                else
                    return false;
            }
            else {
                if(left != null && right != null) {
                    data = right.findMin();
                    right.delete(data, this);
                }
                else if(parent.left == this) {
                    if(left!=null)
                        parent.left = left;
                    else
                        parent.left = right;
                }
                else {
                    if(left!=null)
                        parent.right = left;
                    else
                        parent.right = right;
                }
                return true;
            }
        }

        private int findMin() {
            if(left == null)
                return data;
            return left.findMin();
        }

        private Node getRandomNode(int random) {
            int leftSize = 0;
            if (left != null) leftSize = left.size;


            if (random <leftSize)
                return left.getRandomNode(random);
            else if (random == leftSize)
                return this;
            else {
                return right.getRandomNode(random-leftSize+1);
            }
        }
    }

    public static class BinaryTree {
        Node root = null;

        public BinaryTree(Node root) {
            this.root = root;
        }

        public void insert(int d) {
            if (root == null) {
                Node r = new Node(d);
                root = r;
            }
            else
                root.insert(d);
        }



        public boolean delete(int d) {
            if(root == null)
                return false;

            if(find(d) == null)
                return false;

            if (root.data == d) {
                Node tmpRoot = new Node(-1);
                tmpRoot.left = root;
                boolean didDelete = root.delete(d, tmpRoot);
                if (!didDelete)
                    return false;
                root = tmpRoot.left;
                return true;
            }
            else {
                return root.delete(d, null);
            }
        }

        public Node randomNode() {
            int size = root.size;
            Random random = new Random();
            int r = random.nextInt(size);
            return root.getRandomNode(r);
        }



        public Node find(int d) {
            return root.find(d);
        }

    }



    }
}
