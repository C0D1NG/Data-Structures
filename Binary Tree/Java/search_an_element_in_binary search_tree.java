public Node search_key(Node root, int key) 
{  
    if (root==null || root.key==key) 
        return root; 
        
    //left nodes of binary search tree contains smaller keys than the root node
    if (root.key > key) 
        return search(root.left, key); 
  
    //right nodes of binary search tree contains bigger keys than the root node
    return search(root.right, key); 
} 