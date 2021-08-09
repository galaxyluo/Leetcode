#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement (vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (n == 1) {
            return nums[0] == val ? 0 : 1;
        }
        while (l < r) {
            while (l < n && nums[l] != val)
                l++;
            while (r > 0 && nums[r] == val)
                r--;
            if (l == n || r == 0 || l >= r)
                return l;
            else {
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
            }
        }
        return l;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2};
    cout << s.removeElement(nums, 3);
    return 0;
}