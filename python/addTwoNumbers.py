# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    	if not l1 or not l2:
    		return None
    	res = ListNode()
    	ans = res
    	nxt = 0
    	while l1 or l2:
    		if not l1:
    			l1 = ListNode(0)
    		if not l2:
    			l2 = ListNode(0)

    		tmpNode = ListNode()
    		if nxt == 1:
    			tmp = l1.val + l2.val + 1
    			nxt = 0
    		else:
    			tmp = l1.val + l2.val
    		if tmp >= 10:
    			nxt = 1
    			tmpNode.val = tmp - 10
    			res.next = tmpNode
    			res = res.next
    		else:
    			tmpNode.val = tmp
    			res.next = tmpNode
    			res = res.next
    		l1 = l1.next
    		l2 = l2.next
    	

    	if l1:
    		res.next = l1
    	if l2:
    		res.next = l2
    	if nxt == 1:
    		res.next = ListNode(1)
    	return ans.next


