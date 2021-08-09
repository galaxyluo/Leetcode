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
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> list;
        int prefix = 0;
        int length = A.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + A[i]) % 5;
            list.emplace_back(prefix == 0);
        }
        return list;
    }
};

int main() {
    Solution s;
    vector<int> A = {0, 1, 1, 1, 1};
    vector<bool> res = s.prefixesDivBy5(A);
    vector<bool>::iterator it;
    cout << endl;
    for (it = res.begin(); it != res.end(); it++) {
        cout << *it;
    }
}