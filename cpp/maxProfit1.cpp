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
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cost = 0x7fffffff;
        for (int &price : prices) {
            cost = min(price, cost);
            profit = max(profit, price - cost);
        }
        return profit;
    }
};
int main() {
    Solution s;
    vector<int> pp = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(pp);
    return 0;
}