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
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        board[i][j] = '/0';
        if (dfs(board, word, i + 1, j, k + 1) 
        || dfs(board, word, i, j + 1, k + 1) 
        || dfs(board, word, i - 1, j, k + 1) 
        || dfs(board, word, i, j - 1, k + 1))
            return true;
        board[i][j] = word[k];
        return false;
    }
};