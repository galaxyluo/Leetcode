#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set> 
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int> > board(n, vector<int>(n, 0));
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = unordered_set<int>();
        auto diags1 = unordered_set<int>();
        auto diags2 = unordered_set<int>();
        backtrack(solutions, queens, n, 0, columns, diags1, diags2);
        return solutions;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, unordered_set<int> &columns, unordered_set<int> &diags1, unordered_set<int> &diags2) {
        if (row == n) {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diag1 = row - i;
                if (diags1.find(diag1) != diags1.end()){
                    continue;
                }
                int diag2 = row + i;
                if (diags2.find(diag2) != diags2.end()){
                    continue;
                }
                queens[row] = i;
                columns.insert(i);
                diags1.insert(row - i);
                diags2.insert(row + i);
                backtrack(solutions, queens, n, row + 1, columns, diags1, diags2);
                queens[row] = -1;
                columns.erase(i);
                diags1.erase(row - i);
                diags2.erase(row + i);
            } 
        }    
    }

    vector<string> generateBoard(vector<int> &queens, int n){
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    } 
};
int main() {
    return 0;
}