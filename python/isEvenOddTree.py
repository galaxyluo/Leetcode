# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if not root:
        	return False
        check = True
        queue = [root]
        level = 0
        while queue:
        	res = []
        	level += 1
        	i = 0
        	nodeNum = len(queue)
        	while i < nodeNum:
        		tmp = queue.pop(0)
        		res.append(tmp.val)
        		if tmp.left:
        			queue.append(tmp.left)
        		if tmp.right:
        			queue.append(tmp.right)
        		i += 1



    def checkOrder(self, level: int, nums: List) -> bool:
    	flag = True
    	i = 0
    	while i < len(nums):
    		

