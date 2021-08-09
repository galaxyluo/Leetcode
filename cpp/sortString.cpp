#include<iostream>
#include<string>
#include<vector>


class Solution {
public:
    string sortString(string s) {
        vector<int> num(26);
        for (int i = 0; i < s.length(); i++) {
            num[s[i] - 'a']++;
        }
        string res;
        while (res.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (num[i]) {
                    res.push_back('a' + i);
                    num[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (num[i]) {
                    res.push_back('a' + i);
                    num[i]--;
                }
            }
        }
        return res;
    }
};