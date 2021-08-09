class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.length();
        vector<vector<int>> res;
        if(n < 3) {
            return res;
        }
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            }
            else {
                if (count >= 3) {
                    vector<int> tmp;
                    tmp.push_back(i - 1 - count);
                    tmp.push_back(i - 1);
                    res.push_back(tmp);
                    count = 1;
                }
            }
        }
        return res;
    }
};