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
    int majorityElement(vector<int>& nums) {
        if (!nums.size())
            return NULL;
        int ans = 0, cnt = 0;
        for (int i: nums) {
            if (!cnt) {
                ans = i;
            }
            if (i == ans)
                cnt++;
            else
                cnt--;
        }
        return ans; 
    }
};