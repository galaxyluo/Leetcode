#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLength(vector<string>& arr) {
        string cur;
        backtrack(arr, 0, cur);
        return ans;
    }

    bool check(string& str, string s) {
        unordered_map<char, bool> m;
        string tmp = str + s;
        for (int i = 0; i < tmp.length(); i++) {
            if (m.find(tmp[i]) != m.end()) {
                return false;
            }
            m[tmp[i]] = true;
        }
        return true;
    }
    int ans = 0;
    
    void backtrack(vector<string>& arr, int start, string& cur) {
        if (start == arr.size()) {
            ans = cur.size() > ans ? cur.size() : ans;
            return;
        }
        for (int i = start; i < arr.size(); i++) {
            if (!check(cur, arr[i])) {
                continue;
            }
            string tmp = cur;
            cur += arr[i];
            ans = cur.size() > ans ? cur.size() : ans;
            backtrack(arr, start + 1, cur);
            cur = tmp;
        }
    }
};

int main() {
    Solution s;
    vector<string> arr = {"un", "iq", "ue"};
    cout << s.maxLength(arr);
    return 0;
}