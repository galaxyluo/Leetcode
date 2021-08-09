class Solution:
    def smallestDifference(self, a: List[int], b: List[int]) -> int:
    	lena = len(a)
    	lenb = len(b)
    	a.sort()
    	b.sort()
    	minNum = 2147483647
    	i = j = 0
    	tmpRes = 0
    	while i < lena and j < lenb:
    		tmpRes = a[i] - b[j]
    		if tmpRes >= 0:
    			j += 1
    		else:
    			i += 1
    			tmpRes = 0 - tmpRes

    		minNum = min(minNum, tmpRes)


    	return minNum
