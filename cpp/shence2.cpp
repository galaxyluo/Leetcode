#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int goodNumber(long x, long y, long m) {
        if (x >= m || y >= m)
            return 0;
        if (x <= 0 && y <= 0)
            return -1;
        if (x > y) {
            x = x + y;
            y = x - y;
            x = x - y;
        }
        int cnt = 0;
        while (x < m && y < m) {
            cnt++;
            x = x + y;
            if (x > y) {
                x = x + y;
                y = x - y;
                x = x - y;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    long x, y, m;
    cin >> x >> y >> m;
    cout << s.goodNumber(x, y, m);
    return 0;
}