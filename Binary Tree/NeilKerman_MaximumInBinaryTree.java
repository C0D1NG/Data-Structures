class Node { 
    int info; 
    Node left, right; 
  
    public Node(int info) 
    { 
        this.info = info; 
        left = right = null; 
    } 
} 
  
class NeilKerman_MaximumInBinaryTree { 
    Node start; 
  
    // calculates the max value using recursion
    static int findMax(Node node) 
    { 
        if (node == null) 
            return Integer.MIN_VALUE;
  
        int res = node.info; 
        int lres = findMax(node.left); 
        int rres = findMax(node.right); 
  
        if (lres > res) 
            res = lres; 
        if (rres > res) 
            res = rres; 
        return res; 
    } 
    public static void main(String args[]) 
    { 
        //Initiating the binary tree
        NeilKerman_MaximumInBinaryTree tree = new NeilKerman_MaximumInBinaryTree(); 
        tree.start = new Node(10); 
        tree.start.left = new Node(16); 
        tree.start.right = new Node(25); 
        tree.start.left.right = new Node(32); 
        tree.start.left.right.left = new Node(8); 
        tree.start.left.right.right = new Node(22); 
        
        int max = tree.findMax(tree.start); //gets the max value

        if(max == Integer.MIN_VALUE){
            System.out.println("No Node is found in the tree");
            return;
        }

        System.out.println("Maximum element is " + max); //output
    } 
} 

//code by NeilKerman
