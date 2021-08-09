#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <set> 
using namespace std;
const int mod = 1000000007;
class Solution {
public:
    int myPow(int base, int power) {
        long long result = 1;
        for (; power; power >>= 1) {
            if (power & 1) {
                result = (long long)result * base % mod;
            }
            base = (long long)base * base % mod;
        }
        return result;
    }
    int cuttingRope(int n) {
        if (n <= 2)
            return 1;
        else if (n == 3)
            return 2;
        int num_3 = n / 3;
        int left = n % 3;
        if (left == 0) {
            return myPow(3, num_3) % mod;
        }
        else if (left == 1) {
            return (long long)(myPow(3, num_3 - 1) * 4) % mod;
        }
        else {
            return (long long)(myPow(3, num_3) * 2) % mod;
        }
    }
};