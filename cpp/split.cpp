#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> split(string& str, char splitor) {
        vector<string> ans;
        int cnt = 0;
        int start = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != splitor)
                cnt++;
            else if (cnt == 0){
                start++;
            } else {
                ans.push_back(str.substr(start, cnt));
                start = i + 1;
                cnt = 0;
            }
        }
        if (cnt) {
            ans.push_back(str.substr(start, cnt));
        }
        for (auto& s: ans) {
            cout << s << endl;
        }
        return ans;
    }
};

int main() {
    string str = "...aa.ss...dd.fffff.1";
    Solution s;
    vector<string> ans = s.split(str, '.');
    return 0;
}