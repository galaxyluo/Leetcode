#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1, 1);
        vector<int> pointers(primes.size(), 1);
        for (int i = 2; i <= n; i++) {
            int next = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                next = min(next, dp[i - 1] * primes[j]);
            }

            for (int j = 0; j < primes.size(); j++) {
                if (dp[i - 1] * primes[j] == next) {
                    ++pointers[j];
                }
            }
        }
        return dp[n];
    }
};

int main() {
}