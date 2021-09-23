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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }

        while (q != nullptr) {
            if (vis[q->val])
                return q;
            q = fa[q->val];
        }
        return nullptr;
    }
private:
    unordered_map<int, bool> vis;
    unordered_map<int, TreeNode *> fa;
    void dfs(TreeNode* root) {
        if (root->left) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
};