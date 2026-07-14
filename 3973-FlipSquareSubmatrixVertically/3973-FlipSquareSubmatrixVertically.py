# Last updated: 7/14/2026, 3:19:51 PM
class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for j in range(y,y+k):
            last = x+k-1
            for i in range(x,x+k//2):
                grid[i][j],grid[last][j] = grid[last][j],grid[i][j]
                last -=1
        return grid
