class Solution:
    def longestMountain(self, A: List[int]) -> int:
    	if len(A) < 3:
    		return 0
    	left = 0
    	if A[1] > A[0]:
    		isDown = False
    	else:
    		isDown = True

    	ans = 0
    	for i in range(1, len(A)):
    		if A[i] > A[i - 1]: 
    			if isDown:
    				ans = max(ans, i - left - 1)
    				left = i - 1
    		if A[i] < A[i - 1]:
    			if not isDown:
    				isDown = True
    	if isDown:
    		ans = max((len(A) - left), ans)
    	return ans

