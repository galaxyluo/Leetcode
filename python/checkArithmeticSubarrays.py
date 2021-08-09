class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
    	ans = []
    	for i in range(len(l)):
    		checkNum = nums[l[i]:r[i] + 1]
    		ans.append(self.checkArithmetic(checkNum))

    	return ans

    def checkArithmetic(self, nums: List[int]) -> bool:
    	if len(nums) <= 2:
    		return True
    	nums = sorted(nums)
    	tmp = nums[1] - nums[0]
    	for i in range(2, len(nums)):
    		if tmp != nums[i] - nums[i - 1]:
    			return False

    	return True
