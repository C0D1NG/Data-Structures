class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
        
def Preorder(root):
    if root:
        #first print the data of the node
        print(root.val)
        
        # recur on left child
        Preorder(root.left)
        
        # recur on right child
        Preorder(root.right)
    

# Driver code 
root = Node(1) 
root.left      = Node(2) 
root.right     = Node(3) 
root.left.left  = Node(4) 
root.left.right  = Node(5) 
print("Preorder traversal of binary tree is")
Preorder(root)