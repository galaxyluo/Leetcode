#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int& i: chalk) {
            sum += i;
        }
        int left = k % sum;
        int ans = 0;
        if (left == 0)
            return 0;
        else {
            int i = 0;
            sum = 0;
            while (true) {
                sum += chalk[i];
                if (sum > left) {
                    ans = i;
                    break;
                }
                i = (i + 1) % chalk.size();
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> chalk = {5,1,5};
    int k = 22;
    cout << s.chalkReplacer(chalk, k);
    return 0;
}