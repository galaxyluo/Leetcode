#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int n) {
        if (n == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = n; i < nums.size(); i++) {
            swap(nums[n], nums[i]);
            backtrack(nums, n + 1);
            swap(nums[n], nums[i]);
        }
    }
    vector<vector<int>> ans;
    //vector<int> cur;
};

class Solution2 {
public:
    vector<vector<int>> permute2(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int n) {
        if (n == nums.size()) {
            ans.emplace_back(nums);
        }

        for (int i = n; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end())
                continue;
            used[nums[i]] = true;
            swap(nums[i], nums[n]);
            backtrack(nums, n + 1);
            swap(nums[i], nums[n]);
        }
    }
    map<int, bool> used;
    vector<vector<int>> ans;
}