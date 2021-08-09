class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push(i);
            if (senate[i] == 'D') dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front()) {
                dire.pop();
                int i = radiant.front();
                radiant.pop();
                radiant.push(i + n);
            }
            else {
                radiant.pop();
                int i = dire.front();
                dire.pop();
                dire.push(i + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};