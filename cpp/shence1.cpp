#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void match(string& str) {
        stack<int> st;
        vector<int> ans;
        map<int, int> match;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(') {
                st.push(i);
            }
            if (str[i] == ')') {
                int left = st.top();
                st.pop();
                match[left] = i;
            }
        }
        cout << match.size() << endl;
        for (auto it = match.begin(); it != match.end(); it++) {
            cout << it->first << endl;
            cout << it->second << endl;
        }
        return;
    }

};

int main() {
    string str;
    cin >> str;
    Solution s;
    s.match(str);
    return 0;
}