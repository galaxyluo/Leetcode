# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        temp = root
        if not root:
        	return
        while temp:
        	if temp.left:
        		pre = nxt = temp.left
        		while pre.right:
        			pre = pre.right
        		pre.right = temp.right
        		temp.left = None
        		temp.right = nxt
        	temp = temp.right
    
