class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
    	def build(i_left, i_right):
    		if i_left > i_right:
    			return None

    		val = postorder.pop()
    		root = TreeNode(val)
    		index = dic[val]
    		root.right = build(index + 1, i_right)
    		root.left = build(i_left, index - 1)
    		return root


    	dic = {val: idx for idx, val in enumerate(inorder)}
    	return build(0, len(inorder) - 1)