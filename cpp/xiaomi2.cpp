#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool exist(vector<vector<char>>& matrix, string& str) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        return dfs(matrix, used, str, 0, 0, 0);
    }
private:
    bool dfs(vector<vector<char>>& matrix, vector<vector<bool>>& used, string& str, int n, int i, int j) {
        if (matrix[i][j] != str[n])
            return false; //该结点访问过或该结点与第n个字符不同
        else if (n == str.size() - 1)
            return true; //字符相等且长度够

        used[i][j] = true;
        bool res = false;
        for (auto& dir: dirs) {
            int newi = i + dir.first;
            int newj = j + dir.second;
            if (newi < 0 || newi >= matrix.size() || newj < 0 || newj >= matrix[0].size()) {
                continue;
            }
            else {
                if (!used[newi][newj]) {
                    res = dfs(matrix, used, str, n + 1, newi, newj);
                    if (res)
                        break;
                }
            }
        }
        used[i][j] = false;
        return res;
    }

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
