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
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        if (!matrix.size() || !matrix[0].size())
            return {};
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans;
        int left = 0, right = col - 1, top = 0, bottom = row - 1;
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            for (int i = top + 1; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            if (left < right && top < bottom) {
                for (int j = right - 1; j > left; j--)
                    ans.push_back(matrix[bottom][j]);
                for (int i = bottom; i > top; i--)
                    ans.push_back(matrix[i][left]);
            }
            left++;
            top++;
            right--;
            bottom--;
        }
        return ans;
    }
};