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
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1, col = 0;
        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target) {
                row--;
            }
            else {
                col++;
            }
        }
        return false;
    }
};