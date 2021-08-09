#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeAB(string& str) {
        int pre = 0, cur = 1;
        string ans = "0" + str;
        while(cur <= str.size()) {
            //cout << str.size() << endl;
            cout << ans << endl;
            if (ans[pre] == 'a' && ans[cur] == 'b') {
                ans = ans.erase(pre, 2);
                pre--;
                cur = pre + 1;
            }
            else {
                pre++;
                cur++;
            }
        }
        return ans.erase(0, 1);
    }
};
int main() {
    string str = "aabbccddfsa";
    Solution s;
    cout << s.removeAB(str) << endl;
    return 0;
}