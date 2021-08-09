class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int f_pre = 0, f_cur = 1;
        for (int i = 2; i <= n; i++) {
            int temp = f_cur;
            f_cur = f_pre + f_cur;
            f_pre = temp;
        }
        return f_cur;
    }
};