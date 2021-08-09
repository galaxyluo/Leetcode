class Solution:
    def thirdMax(self, nums: List[int]) -> int:
    	m1 = nums[0]
    	m2 = nums[1]
    	if m1 > m2:
    		
    	for i in range(3, len(nums)):
