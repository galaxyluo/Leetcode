#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int crossRiver(int n, int whiteNum, int blackNum, vector<pair<int, int>>& cost) {
        if (whiteNum > n / 2 || blackNum > n / 2)
            return -1;
        int white = n / 2 - whiteNum;
        int black = n / 2 - blackNum;
        backtrack(cost, white, black, 0);
        return ans;
    }
    int curr;
    int ans;
    void backtrack(vector<pair<int, int>>& cost, int white, int black, int n) {
        if (white == 0 && black == 0) {
            ans = min(curr, ans);
        }

        if (white > 0) {
            curr += cost[n].first;
            backtrack(cost, white - 1, black, n + 1);
            curr -= cost[n].first;
        }
        
        if (black > 0) {
            curr += cost[n].second;
            backtrack(cost, white, black - 1, n + 1);
            curr -= cost[n].first;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cost;
    int whiteNum = 0, blackNum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        if (tmp == 1) {
            whiteNum++;
        }
        else if (tmp == 2) {
            blackNum++;
        }
        else {
            int a, b;
            cin >> a >> b;
            cost.push_back(make_pair(a, b));
        }
    }
    Solution s;
    cout << s.crossRiver(n, whiteNum, blackNum, cost);
    return 0;
}