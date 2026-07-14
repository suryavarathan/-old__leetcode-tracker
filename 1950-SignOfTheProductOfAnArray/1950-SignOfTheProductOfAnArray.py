# Last updated: 7/14/2026, 3:26:17 PM
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        if 0 in nums:
            return 0
        x = 1
        for i in nums:
            x *= i
        def signFunc(x):
            if x > 0:
                return 1
            else:
                return -1
        return signFunc(x)
