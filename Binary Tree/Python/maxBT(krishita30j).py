class newNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def findMax(root):

    if (root == None):
        return float('-inf')

    res = root.data
    lres = findMax(root.left)
    rres = findMax(root.right)
    if (lres > res):
        res = lres
    if (rres > res):
        res = rres
    return res


root = newNode(1)
root.left = newNode(2)
root.right = newNode(3)
root.left.left = newNode(4)
root.left.right = newNode(5)
root.right.left = newNode(6)
root.right.right = newNode(7)
root.right.left.right = newNode(8)
sum = findMax(root)
print("Sum of all the nodes is:", sum)
