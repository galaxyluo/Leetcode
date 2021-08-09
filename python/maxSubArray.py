class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
    	s_idx = e_idx = 0
    	numSum = nums[0]
    	for i in range(1, len(nums)):
    		if nums[i] > numSum + nums[i]:
    			numSum = nums[i]
    			s_idx = i
    			e_idx = i
    		else:
    			e_idx += 1
    			