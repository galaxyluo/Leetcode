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
void dfs(vector<vector<int>>&g, vector<int>& height, int pre,int length) {
    for (int i = 0; i < g.size(); i++) {
        if (i == pre) continue;
        if (g[pre][i] && height[i] < height[pre]) {
            dfs(g, height, i, length + 1);
        }
    }
    length--;
}
int ans;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> height(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> height[i];
    }
    vector<vector<int>> g(m, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        dfs(g, height, i, 0);
    }
    return ans;
}