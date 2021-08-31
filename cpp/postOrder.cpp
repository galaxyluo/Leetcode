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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if (root->right == nullptr || root->right == prev) {
                ans.push_back(root->val);
                prev = root;
                root = nullptr;
            }
            else {
                s.emplace(root);
                root = root->right;
            }
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                ans.push_back(root->val);
                s.emplace(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            
            root = root->right;
        }
        return ans;
    }
};
