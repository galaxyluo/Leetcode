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
#include <unordered_set> 
using namespace std;
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                occ.insert(s[rk + 1]);
                ++rk;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();
        unordered_map<char, int> m;
        int ans = 0;
        int dp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                dp += 1;
                m.insert(make_pair(s[i], i));
            }
            else if (dp >= i - m[s[i]]){
                dp = i - m[s[i]];
                m[s[i]] = i;
            }
            else {
                dp += 1;
                m[s[i]] = i;
            }
            ans = max(dp, ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    string input = "abba";
    cout << s.lengthOfLongestSubstring(input);
    return 0;
}