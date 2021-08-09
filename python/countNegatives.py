'''
class Solution:
    def countNegatives(self, grid):
        m = len(grid)
        n = len(grid[0])
        count = 0
        if grid[m - 1][n - 1] >= 0:
            return 0
        for i in range(m - 1, 0, -1):
            for j in range(n - 1, 0, -1):
                if grid[i][j] < 0:
                    count += 1
                else: continue
        return count
'''
def countNegatives(grid):
        m = len(grid)
        n = len(grid[0])
        count = 0
        if grid[m - 1][n - 1] >= 0:
            return 0
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if grid[i][j] < 0:
                    count += 1
                else: continue
        return count
if __name__ == '__main__':
    grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    print(countNegatives(grid))