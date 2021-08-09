//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode> q;
        q.push(root);
        ans = 1;
        while (!q.empty()) {
            TreeNode *tmp = q.pop();
            ans++;
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
        return ans;
    }
};