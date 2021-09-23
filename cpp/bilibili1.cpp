#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param str string字符串 
     * @return int整型
     */
    int GetFragment(string str) {
        // write code here
        int sum = 0;
        int length = 1;
        int cnt = 0;
        int n = str.size();
        if (n <= 1)
            return n;
        for (int i = 1; i < n; i++) {
            if (str[i] != str[i - 1]) {
                sum += length;
                cnt++;
                length = 1;
            }
            else {
                length++;
            }
        }
        //cout << length << ' ' << endl;
        sum += length;
        cnt++;
        return sum / cnt;
    }
};

int main() {
    string str = "aabbdddddh";
    Solution s;
    s.GetFragment(str);
    return 0;
} 