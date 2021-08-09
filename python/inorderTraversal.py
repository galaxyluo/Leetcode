# Definition for a binary tree node.
#class TreeNode:
#    def __init__(self, x):
#        self.val = x
#        self.left = None
#        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            ans.append(root.val)
            inorder(root.right)
        
        inorder(root)
        return ans
        

