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
    int find(vector<int> &dsu, int n) {
        return n == dsu[n] ? n : (n = find(dsu, dsu[n]));
    }
    void Union(vector<int> &dsu, int x, int y) {
        int fx = find(dsu, x), fy = find(dsu, y);
        dsu[fx] = fy;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> dsu(n, -1);
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1]) {
                    Union(dsu, i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dsu[i] == i) {
                res++;
            }
        }
        return n - res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << s.removeStones(stones);
}