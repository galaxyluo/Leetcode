#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, visit, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtrack(vector<int>& nums, vector<bool>& visit, int n) {
        if (n == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])
                continue;
            if (visit[i])
                continue;
            visit[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, visit, n + 1);
            visit[i] = false;
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = s.permuteUnique(nums);
    for (vector<int> &num: ans) {
        for (int &i: num) {
            cout << i << endl;
        }
    }
    return 0;
}