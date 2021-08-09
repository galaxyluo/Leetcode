class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(0, n);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n; i++) {
            dp[i] = max((dp[i - 1] + 1), (dp[i - 2] + 2));
        }
        return dp[n];
    }
};