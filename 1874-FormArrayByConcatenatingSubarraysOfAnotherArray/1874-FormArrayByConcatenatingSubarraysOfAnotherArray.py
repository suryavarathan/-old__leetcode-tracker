# Last updated: 7/14/2026, 3:28:01 PM
class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        ln=len(groups)
        idx=0
        for i in groups:
            for j in range(idx,len(nums)):
                if nums[j:j+len(i)]==i:
                    idx=j+len(i)
                    ln-=1
                    break
        return ln==0
        