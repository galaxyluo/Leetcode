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
    int find(vector<int>& f, int x) {
        return f[x] == x ? x : f[x] = find(f, f[x]);
    }
    void unionSet(vector<int>& f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        if (fx != fy) {
            f[fx] = fy;
        }
        return;
    }

    int regionsBySlashes(vector<string>& grid) {

    }
};