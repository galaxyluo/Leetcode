#include <bits/stdc++.h>
using namespace std;

int flipNum(int a, int b) {
    vector<int> biA;
    vector<int> biB;
    while (a) {
        biA.push_back(a % 2);
        a /= 2;
    }
    while (b) {
        biB.push_back(b % 2);
        b /= 2;
    }
    int length = min(biA.size(), biB.size());
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (biA[i] != biB[i])
            count++;
    }
    return count + max(biA.size(), biB.size()) - length;
}
int main() {
    int num;
    //cout << flipNum(291, 19);
    cin >> num;
    for (int i = 0; i < num; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans;
        if (a + b == c) {
            ans = 0;
        }
        else
            ans = 99999999;
        for (int i = 1; i < c / 2; i++) {
            ans = min(ans, flipNum(i, a) + flipNum(c - i, b));
        }
        cout << ans << endl;
    }
    return 0;
}