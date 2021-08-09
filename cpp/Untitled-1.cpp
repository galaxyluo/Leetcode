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
int to_int(string str) {
    int num = str.size();
    int ans = 0;
    for(int i = num - 1; i > 0; i++) {
        ans += str[i] - '0' + pow(10, num - i - 1);
    }
    return ans;
}
int main() {
    string str;
    cin >> str;
    vector<int> ans;
    for (int i = 0; i < str.size(); i++) {
        string tmp;
        if (str[i] >= '0' && str[i] <= '9') {
            tmp += str[i];
        }
        else if(tmp != "") {
            while (tmp.size() > 1 && tmp[0] == '0') tmp.erase(0, 1);
            int num = to_int(tmp);
            ans.push_back(num);
            tmp = "";
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}