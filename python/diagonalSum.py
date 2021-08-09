class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
    	row, column = len(mat), len(mat[0])
    	ans = 0
    	for i in range(len(mat) // 2):
    		tmp = mat[i][i] + mat[i][column - i - 1] + mat[row - i - 1][i] + mat[row - i - 1][column - i - 1]
    		ans += tmp
    	if len(mat) % 2 != 0:
    		ans += mat[row // 2][column // 2]
    	return ans