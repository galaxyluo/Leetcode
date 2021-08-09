#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> tmp;
        for (auto &i: nums1) {
            vector<int>::iterator result = find(tmp.begin( ), tmp.end( ), i); 
            if(result == tmp.end()) {
                tmp.push_back(i);
            }
        }
        for (auto &i: nums2) {
            vector<int>::iterator result = find(tmp.begin(), tmp.end(), i); 
            vector<int>::iterator result1 = find(res.begin(), res.end(), i);
            if(result != tmp.end() && result1 == res.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
	Solution s;
	vector<int> nums1 = {1,2,2,1};
	vector<int> nums2 = {2,2};
	s.intersection(nums1, nums2);
} 
