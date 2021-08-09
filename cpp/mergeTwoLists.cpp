#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <set> 
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *dumHead = new ListNode(-1);
        l1->val < l2->val ? dumHead->next = l1 : dumHead->next = l2;
        ListNode *cur = dumHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if (l1)
            cur->next = l1;
        if (l2)
            cur->next = l2;
        return dumHead;
    }
};