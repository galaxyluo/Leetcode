#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        if (n == 1)
            return (nums[0] == target) ? 0 : -1;
        int l = 0, r = n - 1;
        int tmp;
        while (l <= r) {
            tmp = (l + r) / 2;
            if (nums[tmp] == target)
                return tmp;
            if (nums[l] <= nums[tmp]) {
                if (target >= nums[l] && target < nums[tmp]) {
                    r = tmp - 1;
                }
                else {
                    l = tmp + 1;
                }
            }
            if (nums[r] >= nums[tmp]) {
                if (target > nums[tmp] && target <= nums[r]) {
                    l = tmp + 1;
                }
                else {
                    r = tmp - 1;
                }
            } 
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums, 9);
    return 0;
}