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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        int sum;
        dfs(root, sum, ans, tmp);
        return ans;
    }

    void dfs(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& tmp) {
        if (!root) {
            return;
        }
        tmp.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
            ans.push_back(tmp);
        dfs(root->left, sum, ans, tmp);
        dfs(root->right, sum, ans, tmp);
        tmp.pop_back();
    }
};