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
    string convert(string s, int numRows) {
        vector<string> n(min(numRows, int(s.size())));
        if (numRows == 1)
            return s;
        int row = 0;
        int dir = 1;
        for (char c: s) {
            n[row] += c;
            if (row == 0 || row == numRows - 1) dir *= -1;
            row += dir;
        }
        string res;
        for (string s: n) {
            res += s;
        }
        return res;
    }
};

int main() {
    Solution s;
    string str =  "PAYPALISHIRING ";
    cout << s.convert(str, 1);
    return 0;
}