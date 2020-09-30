class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None


def search(root, val):
    if(root == None):
        return False

    if(root.val == val):
        return True

    if(val > root.val):
        return search(root.right, val)
    else:
        return search(root.left, val)


#driver
root = Node(5)
root.left = Node(3)
root.right = Node(10)

toBeSearched = 10

if(search(root, toBeSearched) == True):
    print("FOUND")
else:
    print("NOT FOUND")