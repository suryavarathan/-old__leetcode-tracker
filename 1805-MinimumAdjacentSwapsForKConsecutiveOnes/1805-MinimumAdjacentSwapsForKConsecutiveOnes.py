# Last updated: 7/14/2026, 3:29:16 PM
class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        ii = val = 0 
        ans = inf
        loc = [] # location of 1s
        for i, x in enumerate(nums): 
            if x: 
                loc.append(i)
                m = (ii + len(loc) - 1)//2 # median 
                val += loc[-1] - loc[m] - (len(loc)-ii)//2 # adding right 
                if len(loc) - ii > k: 
                    m = (ii + len(loc))//2 # updated median 
                    val -= loc[m] - loc[ii] - (len(loc)-ii)//2 # removing left 
                    ii += 1
                if len(loc)-ii == k: ans = min(ans, val) # len(ones) - ii effective length
        return ans 