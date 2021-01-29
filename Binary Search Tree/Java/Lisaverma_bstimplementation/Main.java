public class Main {
    public static void main(String[] args) {
        Tree tree = new Tree();

        tree.insert(5);
        tree.insert(7);
        tree.insert(2);
        tree.insert(11);
        tree.insert(65);
        tree.insert(50);

        tree.traverseInOrder();
        System.out.println();
        System.out.println(tree.get(7));
        System.out.println(tree.get(78));
        System.out.println(tree.max());
        System.out.println(tree.min());
        tree.delete(5);
        tree.traverseInOrder();
        System.out.println();
    }
}
