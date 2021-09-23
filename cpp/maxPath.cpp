#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAscPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> used(m, vector<int>(n, 0)); //存放以i,j点为开始的最长上升路径长度
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(matrix, i, j, 0, used);
            }
        }
        int ans = INT_MIN;
        //遍历找出最值
        for (auto& rows: used) {
            for (auto& col: rows) {
                ans = max(ans, col);
            }
        }
        return ans;
    }
private:

    void dfs(vector<vector<int>>& matrix, int i, int j, int currLength, vector<vector<int>>& used) {
        /*
        if (i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0) {
            //越界或者当前值小于前一值，则返回
            cout << i << j << endl;
            return;
        }
        */
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir: dirs) {
            int newi = i + dir.first;
            int newj = j + dir.second;
            if (newi >= matrix.size() || newi < 0 || newj >= matrix[0].size() || newj < 0) return;
            if (matrix[newi][newj] <= matrix[i][j]) {
                //下一个结点比当前结点小，返回
                return;
            }
            if (used[newi][newj] != 0) {
                //新节点已经访问过，直接更新used值
                used[i][j] = max(currLength, used[newi][newj] + 1);
                return;
            }
            //若新节点未被访问，则继续DFS
            dfs(matrix, newi, newj, currLength + 1, used);
        }
        return;
    }
};

int main() {
    vector<vector<int>> nums = {{9,9,4},
                                {6,6,8},
                                {2,1,1}};
    Solution s;
    cout << s.maxAscPath(nums);
    return 0;
}