#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void reverse(string &str) {
        string ans;
        stack<char> tmp;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                tmp.push(str[i]);
            }
            if (str[i] == ' ' && str[i - 1] != ' ') {
                while (!tmp.empty()) {
                    cout << tmp.top();
                    tmp.pop();
                }
                cout << ' ';
            }
        }
    }
};

int main() {
    Solution s;
    string str;
    getline(cin, str);
    s.reverse(str);
    return 0;
}