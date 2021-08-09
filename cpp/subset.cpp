#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int n;
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int start)
    {
        res.push_back(curr);
        for (int i = start; i < n; ++i)
        {
            curr.push_back(nums[i]);
            dfs(nums, res, curr, i+1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, res, curr, 0);
        return res;
    }
};
