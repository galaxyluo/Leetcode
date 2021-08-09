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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int ind = 0;
        for (int i: pushed) {
            s.push(i);
            while (!s.empty() && s.top() == popped[ind]) {
                s.pop();
                ind++;
            }
        }
        return (s.empty() ? true : false);
    }
};