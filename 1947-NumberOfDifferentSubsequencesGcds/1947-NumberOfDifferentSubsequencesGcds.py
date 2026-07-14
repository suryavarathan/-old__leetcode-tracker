# Last updated: 7/14/2026, 3:26:19 PM
class Solution:
    def countDifferentSubsequenceGCDs(self, nums):
        nums, total, mx = set(nums), 0, max(nums)

        for i in range(1,mx+1):
            gcd_ = 0
            for j in range(i,mx+1,i):
                if j in nums:
                    gcd_ = math.gcd(gcd_,j)

            if gcd_ == i:
                total += 1

        return total







        




