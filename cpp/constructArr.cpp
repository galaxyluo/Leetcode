#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.size() <= 1)
            return a;
        int n = a.size();
        vector<int> res(n);
        res[0] = 1;
        int tmp = a[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                res[j] = res[j] * a[i];
            }
            res[i] = tmp;
            tmp = tmp * a[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> res = s.constructArr(a);
    for (int i = 0; i < a.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}