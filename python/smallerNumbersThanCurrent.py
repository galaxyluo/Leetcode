class Solution:
    def smallerNumbersThanCurrent(self, nums):
        sorted_list = sorted(nums)
        sums = [0] * 101

        for i in range(len(sorted_list) - 1):
            if sorted_list[i + 1] > sorted_list[i]:
                sums[sorted_list[i + 1]] = i + 1
        
        return [sums[num] for num in nums]