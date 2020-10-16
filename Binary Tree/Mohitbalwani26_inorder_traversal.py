# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        stack = [(False, root)]
        ans = []
        while stack:
            visited, node = stack.pop()
            if node:
                if not visited:
                    stack.append((False, node.right))
                    stack.append((True, node))
                    stack.append((False, node.left))
                else:
                    ans.append(node.val)
        return ans
