#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        backtrack(nums, 0, visit);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtrack(vector<int>& nums, int n, vector<bool> visit) {
        if (n == nums.size()){
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visit[i])
                continue;
            cur.push_back(nums[i]);
            visit[i] = true;
            backtrack(nums, n + 1, visit);
            cur.pop_back();
            visit[i] = false;
        }
    }
};