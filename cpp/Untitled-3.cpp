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
#include <map>
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
        map<int, int> mmap;
        for (int j = left; j < right; j++) {
            mmap[nums[j]]++;
        }
        int ans = nums[left];
        for (int j = left; j < right; j++) {
            if (mmap[ans] < mmap[nums[j]]) {
                ans = nums[j];
            }
            else if(mmap[ans] == mmap[nums[j]] && ans > nums[j]) {
                ans = nums[j];
            }
        }
        cout << ans << endl;
    }
}