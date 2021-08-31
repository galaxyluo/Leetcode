#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = dfs(board, word, i, j, 0);
                if (flag)
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (board[i][j] != word[k])
            return false;
        else if (k == word.size() - 1) {
            return true;
        }
        char tmp = board[i][j];
        board[i][j] = '#';
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (auto dir: dirs) {
            int nexti = i + dir.first;
            int nextj = j + dir.second;
            if (nexti < board.size() && nexti >= 0 && nextj < board[0].size() && nextj >= 0) {
                if (board[nexti][nextj] != '#') {
                    bool flag = dfs(board, word, nexti, nextj, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        board[i][j] = tmp;
        return result;
    }
};