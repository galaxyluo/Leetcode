#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param arr int整型vector 
     * @param k int整型 允许0变为1的个数
     * @return int整型
     */
    int GetMaxConsecutiveOnes(vector<int>& arr, int k) {
        // write code here
        int left = 0;
        int zero = 0;
        int maxLength = INT_MIN;
        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] == 0)
                zero++;
            while (zero > k) {
                if (arr[left++] == 0) {
                    zero--;
                }
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};