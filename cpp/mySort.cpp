#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void quickSort(vector<int>& nums) {
        partition(0, nums.size() - 1, nums);
    }
    void partition(int l, int r, vector<int>& nums) {
        if (l >= r)
            return;
        int i = l, j = r;
        int pivot = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= pivot)
                j--;
            while (i < j && nums[i] <= pivot)
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        nums[l] = nums[i];
        nums[i] = pivot;
        partition(l, i - 1, nums);
        partition(i + 1, r, nums);
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
    s.mergeSort(nums);
    for (int &num: nums)
        cout << num << ' ';
    return 0;
}