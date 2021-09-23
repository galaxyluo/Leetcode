#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param matrix int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> SpiralMatrix(vector<vector<int> >& matrix) {
        // write code here
        if (!matrix.size() || !matrix[0].size())
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> ans;
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            for (int i = top + 1; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                for (int j = right - 1; j > left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                for (int i = bottom; i > top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return ans;
    }
};