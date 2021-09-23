#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    q.push(make_pair(i, j));
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        grid[x][y] = '0';
                        q.pop();
                        for (auto dir: dirs) {
                            int newx = x + dir.first;
                            int newy = y + dir.second;
                            if (grid[newx][newy] == '1') {
                                q.push(make_pair(newx, newy));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};