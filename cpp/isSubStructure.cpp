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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;
        if (!A || !B)
            return false;
        if (A->val == B->val)
            res = AhaveB(A, B);
        if (!res)
            res = isSubStructure(A->left, B);
        if (!res)
            res = isSubStructure(A->right, B);
        return res;
    }

    bool AhaveB(TreeNode* r1, TreeNode* r2){
        if (!r2)
            return true;
        if (!r1)
            return false;
        if (r1->val != r2->val)
            return false;
        return AhaveB(r1->left, r2->left) && AhaveB(r1->right, r2->right);
    }
};