#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int even, odd;
        int tmp1 = nums[0];
        int tmp2 = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            int tmp = max(tmp1 + nums[i], tmp2);
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        if (n == 3)
            return tmp2;
        int tmp3 = nums[1];
        int tmp4 = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            int tmp = max(tmp3 + nums[i], tmp4);
            tmp3 = tmp4;
            tmp4 = tmp;
        }
        return max(tmp2, tmp4);
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums);
    return 0;
}