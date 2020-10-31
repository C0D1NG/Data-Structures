class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
        
def Inorder(root):
    if root:
        #first recur on left child
        Inorder(root.left)
    
        #print the data of the node
        print(root.val)
    
        # recur on right child
        Inorder(root.right)
    

# Driver code 
root = Node(1) 
root.left      = Node(2) 
root.right     = Node(3) 
root.left.left  = Node(4) 
root.left.right  = Node(5) 
print("Inorder traversal of binary tree is")
Inorder(root)
