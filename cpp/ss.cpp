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
    int m, n;
    cin >> m >> n;
    if (m == 0 && n == 0) {
        return 0;
    }
    vector<vector<int>> martix(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> martix[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << martix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}