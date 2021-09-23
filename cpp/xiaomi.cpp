#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums(m, 0);
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        for (int j = left; j <= right; j++) {
            nums[j] = i + 1;
        }
    }
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        sum = (sum + i * nums[i]) % 100000009;
    }
    cout << sum % 100000009;
    return 0;
}