# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
    	if not head or not head.next:
    		return
    	tmp = ListNode()
    	tmp.next = head
    	pre, cur = tmp, tmp
    	i = n
    	while i > 0:
    		cur = cur.next
    		i -= 1
    	if cur.next:
    		while cur.next != None:
    			cur = cur.next
    			pre = pre.next
    	pre.next = pre.next.next
    	return tmp.next
