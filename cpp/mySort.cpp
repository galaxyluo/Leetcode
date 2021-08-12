#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void quickSort(int left, int right, vector<int>& nums) {
        if (left >= right || left < 0 || right >= nums.size())
            return;
        int i = left, j = right, pivot = nums[left];
        while (i < j) {
            while (i < j && nums[j] <= pivot) {
                j--;
            }
            while (i < j && nums[i] >= pivot) {
                i++;
            }
            if (i < j) {
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            }
        }
        nums[left] = nums[i];
        nums[i] = pivot;
        quickSort(left, i - 1, nums);
        quickSort(i + 1, right, nums);
    }

    void mergeSort(vector<int>& nums) {
        vector<int> tmp(nums.size());
        merge(nums, tmp, 0, nums.size() - 1);
    }
    void merge(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r)
            return;
        int m = (l + r) / 2;
        merge(nums, tmp, l, m);
        merge(nums, tmp, m + 1, r);
        int i = l, j = m + 1;
        for (int k = l; k <= r; k++)
            tmp[k] = nums[k];
        for (int k = l; k <= r; k++) {
            if (i == m + 1)
                tmp[k] = nums[j++];
            else if (j == r + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else
                nums[k] = tmp[j++];
        }
    }
};

int main() {
    vector<int> nums = {1, 56, 23, 6, 67, 8456, 34, 85, 10};
    Solution s;
    s.quickSort(0, nums.size() - 1, nums);
    for (int &num: nums)
        cout << num << ' ';
    return 0;
}