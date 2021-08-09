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
    bool verifyPostorder(vector<int>& postorder) {
        int s = postorder.size();
        if (!s)
            return true;
        return isPostorder(postorder, 0, s - 1);
    }
    bool isPostorder(vector<int>& postorder, int start, int end) {
        int left = 0;
        int root = postorder[end];
        for (int i = start; i < end; i++) {
            if (postorder[i] < root)
                left++;
        }
        for (int i = start + left; i < end; i++) {
            if (postorder[i] < root)
                return false;
        }
        if (left <= 2 && (end - start - left) <= 2)
            return true;
        else if (left <= 2 && (end - start - left) > 2)
            return isPostorder(postorder, start + left, end - 1);
        else if (left > 2 && (end - start - left) <= 2)
            return isPostorder(postorder, start, start + left - 1);
        return isPostorder(postorder, start + left, end - 1) && isPostorder(postorder, start, start + left - 1);
    }
};