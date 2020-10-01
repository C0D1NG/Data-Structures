import random

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def findMax(node):
    if node is None:
        return float("-inf")
    
    leftMax = findMax(node.left)
    rightMax = findMax(node.right)

    return max(node.value, leftMax, rightMax)

array = []

for x in range(10):
    node = Node(random.randint(-100, 100))
    array.append(node)

for x in range(10):
    left = 2 * x + 1
    right = 2 * x + 2
    array[x].left = array[left] if left < 10 else None
    array[x].right = array[right] if right < 10 else None

print(findMax(array[0]))
