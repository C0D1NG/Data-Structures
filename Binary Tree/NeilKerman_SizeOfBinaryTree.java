//Defination of a single node
class Node 
{ 
    int info; 
    Node left, right; 
  
    public Node(int item) 
    { 
        info = item; 
        left = right = null; 
    } 
} 

//class to find the size
class NeilKerman_SizeOfBinaryTree 
{ 
    Node start; //root node
    int size() 
    { 
        return size(start); //starts the recursion
    } 

    int size(Node node) 
    { 
        if (node == null) 
            return 0; 
        else
            return(size(node.left) + 1 + size(node.right)); 
    } 
  
    public static void main(String args[]) 
    { 
        //Initiating the binary tree
        NeilKerman_SizeOfBinaryTree tree = new NeilKerman_SizeOfBinaryTree(); 
        tree.start = new Node(38); 
        tree.start.left = new Node(2); 
        tree.start.right = new Node(10); 
        tree.start.left.left = new Node(16); 
        tree.start.left.right = new Node(20); 
        tree.start.right.left = new Node(56); 
        tree.start.right.right = new Node(22); 
        
        int size = tree.size(); //finds the size of the tree
        System.out.println("The size of given binary tree is: "
                            + size); 
    } 
} 

//code by NeilKerman
