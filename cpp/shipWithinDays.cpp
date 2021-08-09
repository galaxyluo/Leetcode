#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            int mid = (l + r) / 2;
            int day = 1, cur = 0;
            for (int &weight: weights) {
                if (cur + weight > mid) {
                    day++;
                    cur = 0;
                }
                cur += weight;
            }
            if (day <= D) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

};