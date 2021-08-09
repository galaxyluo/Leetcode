#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> factor(int n) {
        vector<int> ans;
        for (int i = 2; i <= n ;i++) {
            while (n != i) {
                if (n % i == 0) {
                    ans.push_back(i);
                    n = n / i;
                }
                else break;
            }
        }
        ans.push_back(n);
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    Solution s;
    vector<int> ans = s.factor(n);
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << '*';
    }
    //cout << ans[ans.size() - 1];
    return 0;
}