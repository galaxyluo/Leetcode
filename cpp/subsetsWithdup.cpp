#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> visit(length);
        dfs(nums, 0, res, tmp, visit, length);
        return res;
    }
private:
    void dfs(vector<int>& nums, int n, vector<vector<int>>& res, vector<int>& tmp, vector<int>& visit, int& length) {
        if (n == length) {
            res.push_back(tmp);
            return;
        }
        if (n == 0 || !(nums[n] == nums[n - 1] && visit[n - 1] == 0)) {
            visit[n] = 1;
            tmp.push_back(nums[n]);
            dfs(nums, n + 1, res, tmp, visit, length);
            visit[n] = 0;
            tmp.pop_back();
        }

        dfs(nums, n + 1, res, tmp, visit, length);
    }
};