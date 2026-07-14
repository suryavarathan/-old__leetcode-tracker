# Last updated: 7/14/2026, 3:26:49 PM
from functools import lru_cache
from collections import Counter

class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        # Step 1: Count how many groups give each remainder
        remainder_counts = [0] * batchSize
        for g in groups:
            remainder_counts[g % batchSize] += 1
        
        happy = remainder_counts[0]  # groups that perfectly match batchSize

        # Step 2: Try to pair complementary remainders
        for i in range(1, (batchSize + 1) // 2):
            if i != batchSize - i:
                match = min(remainder_counts[i], remainder_counts[batchSize - i])
                happy += match
                remainder_counts[i] -= match
                remainder_counts[batchSize - i] -= match
            else:
                # Middle remainder (like 3 in batchSize 6): pair within itself
                match = remainder_counts[i] // 2
                happy += match
                remainder_counts[i] -= match * 2

        # Now we solve the remaining with DFS
        @lru_cache(None)
        def dfs(state, leftover):
            best = 0
            for r in range(1, batchSize):
                if state[r] == 0:
                    continue
                new_state = list(state)
                new_state[r] -= 1
                next_leftover = (leftover + r) % batchSize
                score = dfs(tuple(new_state), next_leftover)
                if leftover == 0:
                    score += 1
                best = max(best, score)
            return best
        
        return happy + dfs(tuple(remainder_counts), 0)