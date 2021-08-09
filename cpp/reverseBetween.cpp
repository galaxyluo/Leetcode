
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int idx = 1;
        ListNode *cur, *nhead;
        nhead->next = head;
        ListNode *start = nhead;
        while (idx < m) {
            start = start->next;
            idx++;
        }
        cur = start->next;
        while (idx <= n && cur) {
            
        }

    }
};