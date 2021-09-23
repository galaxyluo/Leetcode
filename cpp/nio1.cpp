#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @return int整型
     */
    int firstMissingPositive(int* A, int n) {
        // write code here
        for (int i = 0; i < n; i++) {
            if (A[i] < n) {
                swap(A[i], A[A[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    int A[3] = {1, 2, 0};
    int n = 3;
    Solution s;
    cout << s.firstMissingPositive(A, n);
    return 0;
}