public class devmohit_SumOfNode {

    static class Node {
        int data;
        Node left, right;
    }

    static Node Tree(int data) {
        Node node = new Node();
        node.data = data;
        node.left = node.right = null;
        return (node);
    }

    static int SumOfNodes(Node root) {
        if (root == null)
            return 0;
        return (root.data + SumOfNodes(root.left) + SumOfNodes(root.right));
    }

    public static void main(String args[]) {
        Node root = Tree(1);
        root.left = Tree(2);
        root.right = Tree(3);
        root.left.left = Tree(4);
        root.left.right = Tree(5);
        root.right.left = Tree(6);
        root.right.right = Tree(7);
        root.right.left.right = Tree(8);
        root.right.right.right = Tree(9);
        System.out.println("Sum of nodes of Binary Tree is: " + SumOfNodes(root));
    }
}
