#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else
            return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* l, TreeNode *r) {
        if (!l && !r)
            return true;
        else if(!l || !r || l->val != r->val)
            return false;
        else
            return (dfs(l->left, r->right) && dfs(l->right, r->left));
    }
};
