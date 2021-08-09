#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <set> 
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binaryLeft(nums, target + 1) - binaryLeft(nums, target);
    }
    int binaryLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m = 0;
        while (l < r) {
            m = (l + r) >> 1;
            if (nums[m] >= target)
                r = m - 1;
            if (nums[m] < target)
                l = m + 1;
        }
        return l;
    }
};