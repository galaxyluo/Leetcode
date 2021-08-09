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
    void quickSort(vector<string>& strs, int left, int right) {
        if (left >= right) {
            return;
        }
        int l = left;
        int r = right;
        int pivot = l;
        while (l < r) {
            while (l < r && strs[r] + strs[pivot] >= strs[pivot] + strs[r])
                r--;
            while (l < r && strs[l] + strs[pivot] <= strs[pivot] + strs[l])
                l++;
            if (l < r) {
                swap(strs[l], strs[r]);
            }
        }
        swap(strs[l], strs[left]);
        quickSort(strs, left, l - 1);
        quickSort(strs, l + 1, right);
    }
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i : nums) {
            strs.push_back(to_string(i));
        }
        quickSort(strs, 0, strs.size() - 1);
        string ans;
        for (string str: strs) {
            ans += str;
        }
        return ans;
    }
};