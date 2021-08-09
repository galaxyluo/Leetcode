#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> dec;
        int two = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] >= two) {
                while (!dec.empty() && nums[dec.top()] < nums[i]) {
                    two = nums[dec.top()];
                    dec.pop();
                }
                dec.push(i);
            }
            else
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 5, 0, 3, 4};
    cout << s.find132pattern(nums);
}