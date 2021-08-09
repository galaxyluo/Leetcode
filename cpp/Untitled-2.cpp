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
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < k; i++) {
        int left = i, right = i + k - 1;
        vector<int, int> map;
        for (int j = left; j < right; j++) {
            map[nums[j]]++;
        }
        int ans = nums[left];
        for (int j = left; j < right; j++) {
            if (map[ans] < map[nums[j]]) {
                ans = nums[j];
            }
            else if(map[ans] == map[nums[j]] && ans > nums[j]) {
                ans = nums[j]
            }
        }
        cout << ans << endl;
    }
}