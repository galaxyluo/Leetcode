#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> nums;
        for (int i = 0; i <= n; i++) nums.push_back(i);
        vector<int>::iterator it = nums.begin();
        int idx = 0;
        while (nums.size() != 1) {
            int tmp = m % nums.size() - 1;
            idx += tmp;
            idx %= nums.size();
            nums.erase(it + idx);
            idx++;
        }
        return nums[0];
    }
};
int main() {
    Solution s;
    cout << s.lastRemaining(5, 2);
    return 0;
}