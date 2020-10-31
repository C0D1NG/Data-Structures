class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
        
def Postorder(root):
    if root:
        #first recur on left child
        Postorder(root.left)
        
        # recur on right child
        Postorder(root.right)
        
        #print the data of the node
        print(root.val)
    

# Driver code 
root = Node(1) 
root.left      = Node(2) 
root.right     = Node(3) 
root.left.left  = Node(4) 
root.left.right  = Node(5) 
print("Postorder traversal of binary tree is")
Postorder(root)