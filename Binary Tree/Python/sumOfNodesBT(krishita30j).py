class newNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def addBT(root):
    if (root == None):
        return 0
    return (root.key + addBT(root.left) +
            addBT(root.right))


root = newNode(1)
root.left = newNode(2)
root.right = newNode(3)
root.left.left = newNode(4)
root.left.right = newNode(5)
root.right.left = newNode(6)
root.right.right = newNode(7)
root.right.left.right = newNode(8)
sum = addBT(root)
print("Sum of all the nodes is:", sum)
