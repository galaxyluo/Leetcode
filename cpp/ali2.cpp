#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    float p1 = (1 / (n / 2.0));
    float time1 = (n + 1) / 2;
    float ex1 = p1 * time1;
    float time2 = 0.0;
    for (int i = 0; i < n / 2; i++) {
        int length = n - 1 - i - 1;
        int sum = 0;
        for (int x = length - 1; x >= (length + 1) / 2; x--) {
            sum += x;
        }
        time2 += sum / (length / 2.0);
    }
    float ex2 = p1 * time2;
    printf("%.4f", ex1 + ex2);
    return 0;
}