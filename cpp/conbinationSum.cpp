#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, 0, ans, cur, target, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int start, vector<vector<int>>& ans, vector<int>& cur, int target, int n) {
        if (n == target) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (n + candidates[i] > target)
                continue;
            else {
                cur.push_back(candidates[i]);
                dfs(candidates, i, ans, cur, target, n + candidates[i]);
                cur.pop_back();
            }
        }
    }
};