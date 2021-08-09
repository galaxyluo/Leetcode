class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<int, int> position;
        for (int i = 0; i < n; i++) {
            if (position.count(s[i])) {
                position[s[i]] = -1;
            }
            else {
                position[s[i]] = i;
            }
        }
        int first = n;
        for (auto [_, pos] : position) {
            if (pos != -1 && pos < first) {
                fisrt = pos;
            }
        }
        if (first == n) {
            first = -1;
        }
        return first;
    }
};