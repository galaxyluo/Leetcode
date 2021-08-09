#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root;
        stack<TreeNode *> st;
        while (!st.empty() || curr) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        int ans = 9999999;
        for (int i = 1; i < res.size(); i++) {
            ans = min(res[i] - res[i - 1], ans);
        }
        return ans;
    }
};