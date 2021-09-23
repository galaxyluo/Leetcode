#include <bits/stdc++.h>
using namespace std;
class Visit {
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        // write code here
        //动态规划，表示到该位置有多少
        pair<int, int> manager;
        pair<int, int> bussiness;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) {
                    manager.first = i;
                    manager.second = j;
                }
                if (map[i][j] == 2) {
                    bussiness.first = i;
                    bussiness.second = j;
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int dx = -1, dy = -1;
        if (manager.first < bussiness.first) {
            dx = 1;
        }
        if (manager.second < bussiness.second) {
            dy = 1;
        }

        for (int i = manager.first; i != bussiness.first + dx; i = i + dx) {
            if (map[i][manager.second] != -1) {
                dp[i][manager.second] = 1;
            }
        }
        for (int i = manager.second; i != bussiness.second + dy; i = i + dy) {
            if (map[manager.first][i] != -1) {
                dp[manager.first][i] = 1;
            }
        }
        for (int i = manager.first + dx; i != bussiness.first + dx; i = i + dx) {
            for (int j = manager.second + dy; j != bussiness.second + dy; j = j + dy) {
                if (i != manager.first || j != manager.second) {
                    if (map[i][j] != -1) {
                        dp[i][j] = dp[i - dx][j - dy];
                    }
                }
            }
        }
        return dp[bussiness.first][bussiness.second];
    }
};