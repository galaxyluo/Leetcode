class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int tmp = N;
        vector<int> vec;
        while (tmp) {
            vec.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] < vec[i + 1]) {
                for (int j = 0; j <= i; j++) {
                    vec[j] = 9;
                }
                vec[i + 1] -= 1;
            }
        }
        reverse(vec.begin(), vec.end());
        int res = 0;
        for (int i = 0; i < vec.size(); i++) {
            res += vec[i] * pow(10, vec.size() - i - 1);
        }
        return res;
    }
};