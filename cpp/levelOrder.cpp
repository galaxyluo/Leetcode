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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> tree;
        vector<int> res;
        if (!root) {
            return res;
        }
        tree.push(root);
        while(!tree.empty()) {
            TreeNode *tmp = tree.front();
            res.push_back(tmp->val);
            tree.pop();
            if (tmp->left) {
                tree.push(tmp->left);
            }
            if (tmp->right) {
                tree.push(tmp->right);
            }
        }
        return res;
    }
};