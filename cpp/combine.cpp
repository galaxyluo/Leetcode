#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(1, 0, n, k, ans, cur);
        return ans;
    }
    void dfs(int start, int length,int n, int k, vector<vector<int>>& ans, vector<int>& cur) {
        if (length == 2) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i <= k; i++) {
            cur.push_back(i);
            dfs(i + 1, length + 1, n, k, ans, cur);
            cur.pop_back();
        }
    }
};
int main() {
    Solution s;
    int n = 4, k = 2;
    vector<vector<int>> ans = s.combine(4, 2);
    return 0;
}