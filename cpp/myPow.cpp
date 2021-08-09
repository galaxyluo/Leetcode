class Solution {
public:
    double multi(double x, long long N) {
        double ans = 1.0;
        double x_contr = x;
        while (N > 0) {
            if ((N % 2) == 1) {
                ans *= x_contr;
            }
            x_contr *= x_contr;
            N /= 2;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? multi(x, N) : 1.0 / multi(x, -N);
    }
};