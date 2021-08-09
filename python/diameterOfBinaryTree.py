Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res = 1
        def depth(node: TreeNode):
            if node == None: 
                return 0
            left = depth(node.left)
            right = depth(node.right)

            self.res = max(self.res, left + right + 1)
            return max(left, right) + 1
        
        depth(root)
        return self.res - 1
