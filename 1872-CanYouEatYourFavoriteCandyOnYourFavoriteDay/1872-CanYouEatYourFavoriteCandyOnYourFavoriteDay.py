# Last updated: 7/14/2026, 3:28:04 PM
class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        presum = [0]
        for x in candiesCount:
            presum += presum[-1] + x,
        
        def can(t, d, c):
            mn = presum[t]
            mx = mn + candiesCount[t] - 1
            if (d + 1) - 1 > mx:
                return False
            if (d + 1) < (mn + 1) / c:
                return False
            return True
        return [can(*l) for l in queries]