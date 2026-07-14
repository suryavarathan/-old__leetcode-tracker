# Last updated: 7/14/2026, 3:25:42 PM
from typing import List

class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        n = len(nums)
        # Expand outward from start to find first occurrence of target
        for d in range(n):
            for idx in (start - d, start + d):
                if 0 <= idx < n and nums[idx] == target:
                    return d
        return -1  # Should never reach due to guaranteed existence