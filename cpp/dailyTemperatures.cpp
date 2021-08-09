#include <stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> inc;
        for (int i = 0; i < n; ++i) {
            while (!inc.empty() && T[inc.top()] < T[i]) {
                int idx = inc.top();
                inc.pop();
                ans[idx] = i - idx;
            }
            inc.push(i);
        }
        return ans;
    }
};