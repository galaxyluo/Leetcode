#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(n, vector<int>(1 << n));
        int ans;
        for (int i = 0; i < graph.size(); i++) {
            q.emplace(i, 1 << i, 1);
            vis[i][1 << i] = 1;
        }
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }
            for (int i: graph[u]) {
                int mask_i = mask | (1 << i);
                if (vis[i][mask_i] == 0) {
                    q.emplace(i, mask_i, dist + 1);
                    vis[i][mask_i] = 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{1}, {0,2,4}, {1,3,4}, {2}, {1,2}};
    cout << s.shortestPathLength(graph);
    return 0;
}