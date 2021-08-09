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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2)
            return false;
        vector<int> leaf1, leaf2;
        postOrder(root1, leaf1);
        postOrder(root2, leaf2);
        if (leaf1.size() != leaf2.size())
            return false;
        for (int i = 0; i < leaf1.size(); i++){
            if (leaf1[i] != leaf2[i])
                return false;
        }
        return true;
    }
    void postOrder(TreeNode* node, vector<int> leaf) {
        if (node->left) {
            postOrder(node->left, leaf);
        }
        if (node->right) {
            postOrder(node->right, leaf);
        }
        if (!node->left && !node->right) {
            leaf.push_back(node->val);
        }
        return;
    }
};