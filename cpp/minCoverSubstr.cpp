#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T) {
        // write code here
        int n = S.size();
        int left = 0, right = 0;
        int match = 0;
        unordered_map<char, int> charNum;
        unordered_map<char, int> window;
        int ans = INT_MAX;
        int start = 0;
        for (auto& ch: T) {
            charNum[ch]++;
        }
        while (right < n) {
            char ch = S[right];
            if (charNum.count(ch)) {
                //该字符T中有
                window[ch]++;
                if (window[ch] == charNum[ch]) match++; //window中字符出现次数与T中相同，则匹配度加1
            }
            right++;
            while (match == charNum.size()) {
                //window中字符出现情况与T中一样，可作为候选结果
                if (right - left < ans) {
                    ans = right - left;
                    start = left;
                }
                char ch2 = S[left];
                if (charNum.count(ch2)) {
                    window[ch2]--;
                    if (window[ch2] < charNum[ch2]) match--;
                }
                left++;
            }
        }
        return ans == INT_MAX ? "" : S.substr(start, ans);
    }
};