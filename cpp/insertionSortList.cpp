struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode *dhead = new ListNode(0);
        ListNode *pre = dhead;
        ListNode *cur = head;
        while(cur != nullptr){
            while(pre->next != nullptr && pre->next->val < cur->val){
                pre = pre->next;
            }
            ListNode* next = cur->next; 
            cur->next = pre->next; 
            pre->next = cur;
            pre = dummyHead; 
            cur = next;
        }
        return dhead.next;
    }
};