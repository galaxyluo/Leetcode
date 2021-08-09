class Solution:
    def specialArray(self, nums: List[int]) -> int:
    	nums.sort(reverse = True)
    	start = min(len(nums), nums[0])
    	if start == len(nums):
    		if nums[start - 1] >= start:
    			return start
    		else:
    			return -1

    	while start > 0:
    		if nums[start - 1] >= start and nums[start] < start:
    			return start
    		start -= 1
    	return -1