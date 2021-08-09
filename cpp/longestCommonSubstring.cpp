#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int longestCommonSubstring(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0)
            return 0;
        int n = max(text1.size(), text2.size());
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i < n1; i++) {
            for (int j = 1; j < n2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] += 1;
                }
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};