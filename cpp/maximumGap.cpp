#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int minValue = *min_element(nums.begin(), nums.end());
		int maxValue = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxValue - minValue) / (n - 1));
        int bucketSize = (maxValue - minValue) / d + 1;
        
        vector<pair<int, int> > bucket(bucketSize, {-1, -1});
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minValue) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }
        
        int res = 0;
        int pre = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (pre != -1) {
                res = max(res, bucket[i].first - bucket[pre].second);
            }
            pre = i;
        }
        return res;
    }
};

int main() {
	Solution s;
	vector<int> nums = { 3, 6, 9, 1 };
	printf("%d", s.maximumGap(nums));
};
