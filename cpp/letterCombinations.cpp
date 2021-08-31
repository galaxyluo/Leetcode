#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        dfs(digits, 0);
        return ans;
    }

private:
    void dfs(string& digits, int n) {
        if (n == digits.size()) {
            ans.push_back(curr);
            return;
        }
        int i = digits[n] - '2';

        for (char ch: num2char[i]) {
            curr += ch;
            dfs(digits, n + 1);
            curr.pop_back();
        }
    }
    vector<string> num2char = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string curr;                                
};

int main() {
    Solution s;
    string digits = "234";
    vector<string> ans = s.letterCombinations(digits);
    for (auto a: ans) {
        cout << a << endl;
    }
    return 0;
}