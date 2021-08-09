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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;
        dfs(root, low, high);
        return sum;
    }
    void dfs(TreeNode* node, int low, int high) {
        if (!node)
            return;
        if (node->val >= high) {
            if (node->val == high)
                sum += node->val;
            dfs(node->left, low, high);
        }
        else if (node->val <= low) {
            if (node->val == low)
                sum += node->val;
            dfs(node->right, low, high);
        }
        else if (node->val > low && node->val < high){
            sum += node->val;
            dfs(node->left, low, high);
            dfs(node->right, low, high);
        }
        return;
    }
private:
    int sum = 0;
};