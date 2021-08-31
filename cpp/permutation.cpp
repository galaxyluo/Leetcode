#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return ans;
    }
private:
    vector<string> ans;
    void dfs(string s, int n) {
        if (n == s.size() - 1) {
            ans.push_back(s);
            return;
        }
        set<int> st;
        for (int i = n; i < s.size(); i++) {
            if (st.find(s[i]) != st.end())
                continue;
            st.insert(s[i]);
            swap(s[i], s[n]);
            dfs(s, n + 1);
            swap(s[i], s[n]);
        }
    }
};