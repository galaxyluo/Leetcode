class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
       	idx = 0
        for i in range(len(nums)):
 
        	if nums[idx] == 0:
        		nums.pop(idx)
        		nums.insert(0, 0)
        		idx += 1
        	elif nums[idx] == 2:
        		nums.pop(idx)
        		nums.append(2)
        	elif nums[idx] == 1:
        		idx += 1

        return nums