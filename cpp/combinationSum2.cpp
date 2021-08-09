#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> visit(candidates.size(), false);
        ans.clear();
        cur.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, visit);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(vector<int>& candidates, int target, int start, int sum, vector<bool>& visit) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && visit[i - 1] == false)
                continue;
            cur.push_back(candidates[i]);
            visit[i] = true;
            dfs(candidates, target, i + 1, sum + candidates[i], visit);
            visit[i] = false;
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    s.combinationSum2(candidates, target);
    return 0;
}