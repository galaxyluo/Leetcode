#include <iostream>
#include <set>
#include <vector>
using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        set<int> myset;
        vector<int> ans;
        int length = nums.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < length; i++) {
            myset.insert(nums[i]);
            for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
                if ((nums[i] + *it) <= n && *it != nums[i]) {
                	myset.insert(*it + nums[i]);
				}
            }
        }
        
        //for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
            //cout << *it;
        //}
        
        int i = 1;
        while(myset.size() < n) {
            if (myset.find(i) == myset.end()) {
                myset.insert(i);
                for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
                    if ((i + *it) <= n && *it != i) myset.insert(*it + i);
                }
                ans.push_back(i);
            }
            i++;
        }
        return ans.size();
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,2,31,33};
	int n = 2147483647;
	cout << s.minPatches(nums, n);
	return 0;
}
