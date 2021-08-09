#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <set> 
using namespace std;
class Solution {
public:
    int get(int x) {
        int ans = 0;
        while (x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int movingCount(int m, int n, int k) {
        if (!k)
            return 1;
        queue<pair<int, int>> q;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx >= m || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k)
                    continue;
                q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans += 1;
            }
        }
        return ans;
    }
};