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
    bool isStraight(vector<int>& nums) {
        int zcount = 0;
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0)
                zcount++;
            if (nums[i] + 1 == nums[i + 1])
                continue;
            else
                zcount--;
        }
        return zcount >= 0 ? true : false;
    }
};