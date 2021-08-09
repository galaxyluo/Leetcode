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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next) {
            return head;
        }
        ListNode *myHead = new ListNode(-1);
        myHead->next = head;
        ListNode *cur = head->next;
        ListNode *pre = head;
        while (cur) {
            pre->next = cur->next;
            cur->next = myHead->next;
            myHead->next = cur;
            cur = pre->next;
        }
        return myHead->next;
    }
};