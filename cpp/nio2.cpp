#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        vector<string> ans = split(str, ' ');
        string res = "";
        for (int i = ans.size() - 1; i >= 0; i--) {
            res += ans[i];
            if (i != 0) {
                res += ' ';
            }
        }
        return res;
    }

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
        return ans;
    }
};

int main() {
    string str = "nowcoder. a am I";
    Solution s;
    s.ReverseSentence(str);
    return 0;
}