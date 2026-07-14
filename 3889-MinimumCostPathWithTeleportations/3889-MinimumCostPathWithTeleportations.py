# Last updated: 7/14/2026, 3:20:11 PM
class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        hi = max([max(row) for row in grid])
        dp = None
        costs = [[0] * n for _ in range(m)]
        for x in range(k + 1):
            for i in range(m - 1, -1, -1):
                for j in range(n - 1, -1, -1):
                    # Find minimum cost to reach bottom right cell from cell (i, j)
                    costs[i][j] = inf
                    if i == m - 1 and j == n - 1: # Edge case for bottom right cell
                        costs[i][j] = 0
                    else:
                        # Check down move
                        if i < m - 1:
                            s = costs[i + 1][j] + grid[i + 1][j]
                            if s < costs[i][j]:
                                costs[i][j] = s
                        # Check right move
                        if j < n - 1:
                            s = costs[i][j + 1] + grid[i][j + 1]
                            if s < costs[i][j]:
                                costs[i][j] = s
                        # Check teleportation
                        if x > 0 and dp[grid[i][j]] < costs[i][j]:
                            costs[i][j] = dp[grid[i][j]]
            # Update dp for next iteration
            dp = [inf] * (hi + 1)
            for i in range(m):
                for j in range(n):
                    if costs[i][j] < dp[grid[i][j]]:
                        dp[grid[i][j]] = costs[i][j]
            # Compute prefix min
            dp = list(accumulate(dp, min))
        return costs[0][0] 