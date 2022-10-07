public class adityarajbhagat2002_preorder {

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

    static void preorder(Node root) {
        if (root == null)
            return;
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
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
        System.out.print("preorder traversal of nodes of Binary Tree is: ");
        preorder(root);
    }
}
