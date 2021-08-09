#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        int maxn = nums[0];
        int pos = 0;
        for (int i = 0; i < k; i++) {
            if (nums[i] >= maxn) {
                maxn = nums[i];
                pos = i;
            }
        }
        int left = 0, right = k;
        for (int i = 1; i < length - k; i++) {
            left = left + i;
            right = right + i;
        }
    }
};