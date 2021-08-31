#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) 
            return 0;
        vector<int> leftMax(n); //维护i左边最高的height
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        int leftMax = height[0], rightMax = height[n - 1];
        int ans = 0;
        while (left < right) {
            leftMax = max(left, leftMax);
            rightMax = max(right, rightMax);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                left++;
            }
            if (height[left] >= height[right]) {
                ans += rightMax - height[right];
                right--;
            }
        }
    }
};