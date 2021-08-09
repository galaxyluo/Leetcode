#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void splitListNode(ListNode* list, ListNode* odd, ListNode* even) {
        ListNode *cur = list;
        ListNode *oddhead = odd, *oddeven = even;
        bool isOdd = true;
        while (cur && cur->next) {
            if(isOdd) {
                odd->next = cur;
                odd = odd->next;
            }
            else {
                even->next = even;
                even = even->next;
            }
            isOdd = !isOdd;
            cur = cur->next;
        }
    }

    ListNode* mergeListNode(ListNode *a, ListNode *b) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        while (a && b) {
            if (a->val > b->val) {
                cur->next = a;
                a = a->next;
            }
            else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if (a) {
            cur->next = a;
        }
        if (b) {
            cur->next = b;
        }
        return res->next;
    }
};